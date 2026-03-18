# HW2_Fast_and_Slow_Pointer
Part of HW2 from Linux Kernel Internals 2026. Analyzing cache performance of the 2 implementation of  "finding the middle node" LeetCode Problem

# Agenda
- Explore kernel commit and docs to see how memory is allocated in the
  kernel.
- Plan on `perf` tool usage.



# TODOs
- [x] Decide (perhaps finalize) the main focus of the experiment.
    - Will measure cache performance difference in the 2 solutions to "middle of linked-list" LeetCode Problem presented in learning material.
- [x] Implement memory allocator (using bump allocator strategy).
    - This is optional for now, will do it if time permits.
- [ ] Write a MakeFile that runs experiment(s).
- [ ] Formulate a plan on how to use `perf` (`event_perf`) to benchmark and how to present the data
    - status: 
        - know how to set `perf_event_paranoid` kernel variable to `0`
          (required for measuring CPU cache performance).

# Relevant Linux Commit
1. bf2650d0599c999cf2fdffa721b00e25989918fb
