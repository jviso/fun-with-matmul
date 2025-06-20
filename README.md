# MatMul Fun

## Purpose

This is simply documentation of a little learning journey as I explore:

- Ways to represent matrices
- Algorithms for operations on matrices
- Performance optimizations and their trade-offs
- Options for accelerating code on a GPU
- Impact of programming language on all of the above

## TODO

- [x] Instantiate and print a small matrix
- [x] Write function for printing matrices of arbitrary size
- [x] Implement matmul
- [ ] Examine assembly code for matmul implementation using [`godbolt`](https://godbolt.org) or compiler output
- [ ] Assess runtime latency for matmul as a function of representation and input size
- [ ] Check size of L1 cache on my machine and predict what size matrix will break cache coherence
- [ ] Confirm empirically what dimensions in matrix multiplication will break cache coherence
- [ ] Optimize matmul for memory generally
- [ ] Implement capped-memory matmul algorithm
- [ ] Port some of the above to C++, Zig, or Rust
- [ ] Run matmul on the GPU with as little library support as possible
- [ ] Run matmul on GPU using existing CUDA libraries
