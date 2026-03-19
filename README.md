# HW2: Fast and Slow Pointer

Part of HW2 from [Linux Kernel Internals 2026](https://wiki.csie.ncku.edu.tw/linux/schedule).

Analyzes cache performance of two approaches to the "find middle node" problem:
- **Fast/slow pointer**: single-pass traversal
- **Two-scan**: count length, then traverse to the middle

## Components

- **Linked list**: singly-linked list with head, tail, and size tracking
- **Memory allocator**: bump allocator that pre-allocates a large block and hands out fixed-size chunks
- **Shuffle**: randomizes node addresses to simulate realistic (non-contiguous) memory layouts
- **Data collector**: records address deltas between consecutive nodes

## Experiment

1. Run both middle-finding algorithms on lists of varying sizes
2. Measure cache miss rates using `perf`

## TODO

- [ ] Finalize experiment scope
- [ ] Implement bump allocator
- [ ] Write Makefile to automate experiments
