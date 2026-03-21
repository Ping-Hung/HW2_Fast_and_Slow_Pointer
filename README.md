# HW2: Fast and Slow Pointer
Part of HW2 from [Linux Kernel Internals 2026](https://wiki.csie.ncku.edu.tw/linux/schedule).

# Goal
Analyzes cache performance of two approaches to the "find middle node" problem:
- **Fast/slow pointer**: single-pass traversal
- **Two-scan**: count length, then traverse to the middle

## Components
- **Linked list**: singly-linked list with head, tail, and size tracking
- **Memory allocator**: bump allocator that pre-allocates a large block and hands out fixed-size chunks
    - `Ping-Hung`'s suggestion after reading [what every C programmer should know about memory](https://marek.vavrusa.com/memory/):
        - A ***slab allocator*** might be more suitable in this case, the article above provides example code.
        - If in a time crunch, we'll use whatever we have at the moment.
- **Shuffle**: randomizes node addresses to simulate realistic (non-contiguous) memory layouts
- **Data collector**: records address deltas between consecutive nodes

## Experiment

1. Run both middle-finding algorithms on lists of varying sizes
2. Measure cache miss rates using `perf`

## TODO
- [x] Finalize experiment scope
- [x] Implement an allocator
- [x] Write Makefile to automate experiments
- [ ] Formulate a plan on how to use `perf` (`event_perf`) to benchmark and how to present the data
    - status: 
        - know how to set `perf_event_paranoid` kernel variable to `0`
          (required for measuring CPU cache performance).

# Resources
## Relevant Linux Commit
1. bf2650d0599c999cf2fdffa721b00e25989918fb

## Others
1. [你所不知道的 C 語言：記憶體管理、對齊及硬體特性](https://hackmd.io/@sysprog/c-memory?stext=7004%3A6%3A0%3A1773894618%3ABu6f8x)
2. [what every C programmer should know about memory](https://marek.vavrusa.com/memory/)
3. [The Slab Allocator: An Object-Caching Kernel Memory Allocator (paper that first proposed the slab allocator)](https://people.eecs.berkeley.edu/~kubitron/cs194-24/hand-outs/bonwick_slab.pdf)
