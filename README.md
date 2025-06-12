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
- [ ] Add two matrices
- [ ] Multiply two small small matrics naively
- [ ] Test for what dimensions in matrix multiplication will break cache coherence
  and compare against a theoretical estimate
- [ ] Optimize matmul for memory
- [ ] Implement capped-memory matmul algorithm
- [ ] Port some of the above to C++, Zig, or Rust
- [ ] Run matmul on the GPU with as little library support as possible
- [ ] Run matmul on GPU using existing CUDA libraries
