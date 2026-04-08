# Algebra rings implementation in C++

A lightweight C++ implementation of the mathematical ring $\mathbb{Z}_n$ (where $n \in \mathbb{N}$). 
It provides a generic template class `Ring<N>` that safely handles modular arithmetic operations, including addition, subtraction, multiplication, and division.

The implementation is based on the concept of algebraic rings and modular arithmetic. Division operations calculate the modular multiplicative inverse using the **Extended Euclidean Algorithm**. If the ring is a field (when $N$ is a prime number), every non-zero element has a multiplicative inverse.

More about theory here: 
- https://en.wikipedia.org/wiki/Ring_(mathematics)
- https://en.wikipedia.org/wiki/Multiplicative_group_of_integers_modulo_n

## Project structure

`rings.hpp` - the implementation of Ring class.
`test.cpp` - tests the implementation.

## How to use it and run test.cpp code?

1. To run test.cpp you need the `g++` compiler and run commands in the directory with files `test.cpp` and `rings.hpp`
```
g++ test.cpp
```
and ./a.out to run simple test
```
./a.out
```
