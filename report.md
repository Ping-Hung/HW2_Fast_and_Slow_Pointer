# Middle Finding Algorithms Benchmark Experiment

* [helpful tutorial](https://linuxvox.com/blog/what-are-perf-cache-events-meaning/#understanding-cpu-caches-a-quick-refresher)
## Goal: Benchmark and compare cache behavior of the two algorithms mentioned in class (*2 scan* and *fast-and-slow-pointers* ).

## Experiment Setup
Referring back to [HackMD's Experiment Design](https://hackmd.io/@d1MVB-tCQ92KCHBsW4mrJg/linux2026-hw2?stext=509%3A148%3A0%3A1774135145%3AiSSbet), the experiment will try to mimic real-world memory allocation patterns, which leads to the following program outline.

### Program Outline
1. Allocate memory (from OS) using a self implemented *slab allocator*.
2. Build a linked-list via a *slab allocator*.
3. Randomize the list nodes using [*Fiser-Yates shuffle*](https://hackmd.io/@sysprog/c-linked-list#%E5%AF%A6%E4%BD%9C).
4. Run the middle-finding algorithm of choice (*two-scan* or *fast-and-slow-pointers*).
5. Free all allocated memory.

### Experiment Procedure:
* 3 trials will be run, each time with different number of `list_node`s.
* The three numbers are chosen because they are mentioned in the problem.
* Note that the actual numbers chosen are adjusted to`sizeof(struct list_node)`
  being 16 bytes so we could allocate exactly $10^4$, $10^6$, and $10^8$ nodes.

* `perf` commands:
    1. `perf record -e L1-dcache-load-misses,LLC-load-misses`: track L1d cache
       misses and LLC misses (Last-Level-Cache miss (when CPU *must* fetch
       RAM))
    2. `perf report`: for summary
    3. 



|trial number|trial 1|trial 2|trial 3|
|:---:|:---:|:---:|:---:|
|number of nodes| $10^4$ (160000 bytes) | $10^6$ (16000000 bytes) | $10^8$ (1600000000 bytes)|

## Experiment Environment
### CPU
```
Architecture:                x86_64
  CPU op-mode(s):            32-bit, 64-bit
  Address sizes:             43 bits physical, 48 bits virtual
  Byte Order:                Little Endian
CPU(s):                      8
  On-line CPU(s) list:       0-7
Vendor ID:                   AuthenticAMD
  Model name:                AMD Ryzen 5 3500U with Radeon Vega Mobile Gfx
    CPU family:              23
    Model:                   24
    Thread(s) per core:      2
```
### Caches
```
NAME ONE-SIZE ALL-SIZE WAYS TYPE        LEVEL SETS PHY-LINE COHERENCY-SIZE
L1d       32K     128K    8 Data            1   64        1             64
L1i       64K     256K    4 Instruction     1  256        1             64
L2       512K       2M    8 Unified         2 1024        1             64
L3         4M       4M   16 Unified         3 4096        1             64
```

**Summary:** 4 cores, each has a L1d (data cache) of size 32K

### Operating System
```
Linux IdeaPad-3-15ADA05 6.17.0-19-generic #19~24.04.2-Ubuntu SMP PREEMPT_DYNAMIC Fri Mar  6 23:08:46 UTC 2 x86_64 x86_64 x86_64 GNU/Linux
```

## Results
### $10^4$ Nodes
___
2-scan
```
Samples: 16  of event 'L1-dcache-load-misses', Event count (approx.): 32047
Overhead  Command          Shared Object          Symbol
  12.05%  HW2_linked_list  [unknown]              [k] 0xffffffff82f725ea
  11.95%  HW2_linked_list  HW2_linked_list_cache  [.] mem_free
  11.28%  HW2_linked_list  HW2_linked_list_cache  [.] find_middle_two_scan
  11.03%  HW2_linked_list  libc.so.6              [.] _int_malloc
  10.91%  HW2_linked_list  HW2_linked_list_cache  [.] allocator_init
  10.67%  HW2_linked_list  [unknown]              [k] 0xffffffff821094a0
  10.45%  HW2_linked_list  [unknown]              [k] 0xffffffff81a00b90
   9.34%  HW2_linked_list  ld-linux-x86-64.so.2   [.] _dl_new_object
   7.51%  HW2_linked_list  [unknown]              [k] 0xffffffff82211e45
   3.73%  HW2_linked_list  [unknown]              [k] 0xffffffff82f8e5e7
   0.93%  HW2_linked_list  [unknown]              [k] 0xffffffff82fad580
   0.12%  HW2_linked_list  [unknown]              [k] 0xffffffff81d99b04
   0.02%  perf-exec        [unknown]              [k] 0xffffffff82fab391
```
___
fast-and-slow-pointers
```
Samples: 15  of event 'L1-dcache-load-misses', Event count (approx.): 29714
Overhead  Command          Shared Object          Symbol
  13.20%  HW2_linked_list  HW2_linked_list_cache  [.] mem_free
  12.69%  HW2_linked_list  HW2_linked_list_cache  [.] find_middle_fast_slow
  12.24%  HW2_linked_list  HW2_linked_list_cache  [.] mem_alloc
  12.16%  HW2_linked_list  [unknown]              [k] 0xffffffff8213ccdd
  12.11%  HW2_linked_list  [unknown]              [k] 0xffffffff82f8e5e7
  11.78%  HW2_linked_list  [unknown]              [k] 0xffffffff82fad580
  11.22%  HW2_linked_list  [unknown]              [k] 0xffffffff82102b12
   9.15%  HW2_linked_list  [unknown]              [k] 0xffffffff820fa8f4
   4.37%  HW2_linked_list  [unknown]              [k] 0xffffffff821215fd
   0.94%  HW2_linked_list  [unknown]              [k] 0xffffffff821c0985
   0.13%  HW2_linked_list  [unknown]              [k] 0xffffffff81d99b51
   0.02%  perf-exec        [unknown]              [k] 0xffffffff821f4476
   0.01%  perf-exec        [unknown]              [k] 0xffffffff82fad580
```

### $10^6$ Nodes
___
two-scan
```
Samples: 250  of event 'L1-dcache-load-misses', Event count (approx.): 1484982
Overhead  Command          Shared Object          Symbol
  25.47%  HW2_linked_list  HW2_linked_list_cache  [.] find_middle_two_scan
  14.92%  HW2_linked_list  HW2_linked_list_cache  [.] allocator_init
  14.72%  HW2_linked_list  HW2_linked_list_cache  [.] list_create
  11.64%  HW2_linked_list  HW2_linked_list_cache  [.] mem_free
   8.83%  HW2_linked_list  [unknown]              [k] 0xffffffff82f8e5e7
   5.35%  HW2_linked_list  HW2_linked_list_cache  [.] list_free
   2.14%  HW2_linked_list  HW2_linked_list_cache  [.] mem_alloc

```
___
fast-and-slow-pointers
```
Samples: 261  of event 'L1-dcache-load-misses', Event count (approx.): 1565026
Overhead  Command          Shared Object          Symbol
  22.66%  HW2_linked_list  HW2_linked_list_cache  [.] find_middle_fast_slow
  13.46%  HW2_linked_list  HW2_linked_list_cache  [.] allocator_init
  12.41%  HW2_linked_list  HW2_linked_list_cache  [.] mem_free
   9.61%  HW2_linked_list  [unknown]              [k] 0xffffffff82f8e5e7
   8.43%  HW2_linked_list  HW2_linked_list_cache  [.] mem_alloc
   8.15%  HW2_linked_list  HW2_linked_list_cache  [.] list_create
   4.34%  HW2_linked_list  HW2_linked_list_cache  [.] list_free
```


### $10^8$ Nodes
___
two-scan
```
Samples: 15K of event 'L1-dcache-load-misses', Event count (approx.): 135589989
Overhead  Command          Shared Object          Symbol
  27.82%  HW2_linked_list  HW2_linked_list_cache  [.] find_middle_two_scan
  16.22%  HW2_linked_list  HW2_linked_list_cache  [.] list_create
  10.91%  HW2_linked_list  HW2_linked_list_cache  [.] mem_free
   8.00%  HW2_linked_list  HW2_linked_list_cache  [.] list_free
   6.00%  HW2_linked_list  [unknown]              [k] 0xffffffff82f8e5e7
   4.16%  HW2_linked_list  HW2_linked_list_cache  [.] allocator_init
   2.69%  HW2_linked_list  HW2_linked_list_cache  [.] mem_alloc
```
___
fast-and-slow-pointers
```
Samples: 13K of event 'L1-dcache-load-misses', Event count (approx.): 125733267
Overhead  Command          Shared Object          Symbol
  29.93%  HW2_linked_list  HW2_linked_list_cache  [.] find_middle_fast_slow
  13.21%  HW2_linked_list  HW2_linked_list_cache  [.] list_create
  12.86%  HW2_linked_list  HW2_linked_list_cache  [.] mem_free
   7.63%  HW2_linked_list  HW2_linked_list_cache  [.] list_free
   6.13%  HW2_linked_list  HW2_linked_list_cache  [.] mem_alloc
   4.69%  HW2_linked_list  [unknown]              [k] 0xffffffff82f8e5e7
   2.96%  HW2_linked_list  HW2_linked_list_cache  [.] allocator_init

```


