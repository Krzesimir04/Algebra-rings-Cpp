#pragma once
#include <iostream>
#include <stdexcept>

/**
 * @brief template class representing an element in modular ring or field modulo N.
 * This class handles arthmetic opertaions, inverses and comparisions in within integer quotient ring modulo N.
 */
template <unsigned int N>
class Ring
{
private:
    unsigned int x;

    /**
     * @brief Computes the greatest common divisor for argument and N.
     * @param a The number to find the GCD with N.
     * @return The greatest common divisor of a and N.
     */
    static unsigned int gcd(const unsigned int a)
    {
        int a_cpy = a;
        int tmp;
        int N_cpy = N;
        while (a_cpy > 0)
        {
            tmp = a_cpy;
            a_cpy = N_cpy % a_cpy;
            N_cpy = tmp;
        }
        return N_cpy;
    }

    /**
     * @brief Calculates the modular multiplicative inverse using the Extended Euclidean Algorithm.
     * * @param y The number to invert.
     * @return The multiplicative inverse of y modulo N.
     * @throws const char* Throws a string literal if a and N are not coprime (inverse doesn't exist).
     */
    static unsigned int inverse(const unsigned int y)
    {
        int y_cpy = y, N_cpy = N;
        int a0 = 1, a1 = 0;
        int q, tmp_y, tmp_a;

        while (N_cpy != 0)
        {
            q = y_cpy / N_cpy;
            tmp_y = y_cpy;

            y_cpy = N_cpy;
            N_cpy = tmp_y % N_cpy;

            tmp_a = a0;

            a0 = a1;
            a1 = tmp_a - q * a1;
        }
        if (y_cpy != 1)
        {
            throw std::runtime_error("there is no inverse for that number in the ring.\n");
            return 0;
        }

        int a = a0;
        while (a <= 0)
        {
            a += N;
        }
        return a % N;
    }

    /**
     * @brief Calculates the additive inverse in modulo N.
     * * @param y The number to find the additive inverse for.
     * @return The additive inverse of y modulo N.
     */
    static int inverse_for_sums(const unsigned int y)
    {
        return N - y;
    }

public:
    /**
     * @brief Default constructor initializing the ring element.
     * * @param x The initial value (defaults to 0). It is automatically reduced modulo N.
     */
    Ring(unsigned int x = 0)
    {
        this->x = x % N;
    }

    /**
     * @brief Gets the underlying integer value.
     * @return The stored value x.
     */
    unsigned int get()
    {
        return this->x;
    }

    /**
     * @brief Gets the multiplicative inverse of the current object.
     * @return The inverse value.
     */
    int get_inverse()
    {
        return inverse(this->x);
    }

    /**
     * @brief Gets the additive inverse of the current object.
     * @return The additive inverse value.
     */
    int get_inverse_for_sums()
    {
        return inverse_for_sums(this->x);
    }

    Ring &operator=(int new_x)
    {
        this->x = (new_x % N);
        return *this;
    }
    Ring &operator+=(const Ring &other)
    {
        this->x = ((this->x + other.x) % N);
        return *this;
    }
    Ring &operator-=(const Ring &other)
    {
        this->x = (((this->x + Ring::inverse_for_sums(other.x)) + N) % N);
        return *this;
    }
    Ring &operator*=(const Ring &other)
    {
        this->x = (((this->x * other.x)) % N);
        return *this;
    }
    Ring &operator/=(const Ring &other)
    {
        this->x = (((this->x * Ring::inverse(other.x))) % N);
        return *this;
    }

    // friend - can use with other types
    friend Ring operator+(const Ring &right, const Ring &other)
    {
        return Ring((right.x + other.x) % N);
    }
    friend Ring operator-(const Ring &right, const Ring &other)
    {
        return Ring((right.x + Ring::inverse_for_sums(other.x)) % N);
    }
    friend Ring operator*(const Ring &right, const Ring &other)
    {
        return Ring((right.x * other.x) % N);
    }
    friend Ring operator/(const Ring &right, const Ring &other)
    {
        return Ring((right.x * Ring::inverse(other.x)) % N);
    }

    bool operator==(const Ring &other) const
    {
        return ((this->x % N) == (other.x % N));
    }
    bool operator!=(const Ring &other) const
    {
        return ((this->x % N) != (other.x % N));
    }
    bool operator<(const Ring &other) const
    {
        return ((this->x % N) < (other.x % N));
    }
    bool operator>(const Ring &other) const
    {
        return ((this->x % N) > (other.x % N));
    }
    bool operator<=(const Ring &other) const
    {
        return ((this->x % N) <= (other.x % N));
    }
    bool operator>=(const Ring &other) const
    {
        return ((this->x % N) >= (other.x % N));
    }
    friend std::ostream &operator<<(std::ostream &os, const Ring &r)
    {
        return os << r.x;
    }
    friend std::istream &operator>>(std::istream &is, Ring &r)
    {
        unsigned int tmp;
        if (is >> tmp)
            r.x = (tmp % N);
        return is;
    }
};
