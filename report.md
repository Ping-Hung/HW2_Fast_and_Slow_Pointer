# Middle Finding Algorithms Benchmark Experiment
## Goal: Benchmark and compare cache behavior of the two algorithms mentioned in class (*2 scan* and *fast-and-slow* pointers).


## Experiment Setup
Referring back to [HackMD's Experiment Design](https://hackmd.io/@d1MVB-tCQ92KCHBsW4mrJg/linux2026-hw2?stext=509%3A148%3A0%3A1774135145%3AiSSbet), the experiment will try to mimic real-world memory allocation patterns, which leads to the following design (and steps).

1. Allocate memory (from OS) using a self implemented *slab allocator*.
2. Build a linked-list via *slab allocator APIs (functions)*.
3. Randomize the list nodes using [*Fiser-Yates shuffle*](https://hackmd.io/@sysprog/c-linked-list#%E5%AF%A6%E4%BD%9C).
4. Run the first algorithm (*2 scan*), and benchmark its performance
5. Run the second algorithm (*fast-and-slow pointers*), and benchmark its performance
6. Free all allocated memory.

