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

## Rings implementation - features and details

The implementation uses C++ templates, that allows to define a ring of any size at compile time.

**Key features**
* **Automatic Modular Reduction**: All constructors and operations ensure that the internal value $x$ always stays in the range $[0, N-1]$.
* **Full Operator Overloading**: Supports standard arithmetic (`+`, `-`, `*`, `/`), compound assignments (`+=`, `-=`, `*=`, `/=`), and comparisons (`==`, `!=`, `<`, etc.).
* **I/O Stream Support**: Easily print elements using `std::cout` or read them using `std::cin`.
* **Advanced Algebra**:
    * **Additive Inverse**: Calculated as $(N - x) \pmod N$.
    * **Multiplicative Inverse**: Calculated using the **Extended Euclidean Algorithm**.

### Error Handling
The class ensures mathematical correctness:
* **Division (`/`)**: Attempting to divide by an element that is not coprime to $N$ (i.e., does not have a modular inverse) will throw a `std::runtime_error`.

## How to use it and run test.cpp code?

### Usage example

```cpp
#include "rings.hpp"

int main() {
    Ring<10> a(7);
    Ring<10> b(5);

    auto sum = a + b;     // result: 2 (since 12 mod 10 = 2)
    auto prod = a * b;    // result: 5 (since 35 mod 10 = 5)
    
    // Ring<7> is a field (7 is prime), so every non-zero element has an inverse
    Ring<7> c(3);
    auto inv = c.get_inverse(); // Finds x such that 3*x ≡ 1 (mod 7)
    return 0;
}
```

1. To run test.cpp you need the `g++` compiler and run commands in the directory with files `test.cpp` and `rings.hpp`
```
g++ test.cpp
```
and ./a.out to run simple test
```
./a.out
```
