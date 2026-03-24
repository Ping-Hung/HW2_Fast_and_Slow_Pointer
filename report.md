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
### 
![$10^4$ 2-scan](Screenshot\ from\ 2026-03-24\ 23-36-14.png)

|number of nodes| $10^4$ (160000 bytes) | $10^6$ (16000000 bytes) | $10^8$ (1600000000 bytes)|
|:---:|:---:|:---:|:---:|
|performance |  |  |  |


