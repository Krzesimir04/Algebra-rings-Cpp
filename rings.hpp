#pragma once
#include <iostream>

/**
 * @brief template class representing an element in modular ring or field modulo N.
 * This class handles arithmetic operations, inverses and comparisons within integer quotient ring modulo N.
 */
template <unsigned long long N>
class Ring
{
private:
    unsigned long long x;

    /**
     * @brief Calculates the modular multiplicative inverse using the Extended Euclidean Algorithm.
     * @param y The number to invert.
     * @return The multiplicative inverse of y modulo N.
     * @throws std::runtime_error Throws a exception if y and N are not coprime (inverse doesn't exist).
     */
    static unsigned long long inverse(const unsigned long long y)
    {
        unsigned long long y_cpy = y, N_cpy = N;
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
     * @param y The number to find the additive inverse for.
     * @return The additive inverse of y modulo N.
     */
    static unsigned long long inverse_for_sums(const unsigned long long y)
    {
        return N - y;
    }

public:
    /**
     * @brief Default constructor initializing the ring element.
     * @param x The initial value (defaults to 0). It is automatically reduced modulo N.
     */
    Ring(unsigned long long x = 0)
    {
        this->x = x % N;
    }

    /**
     * @brief Gets the underlying integer value.
     * @return The stored value x.
     */
    unsigned long long get()
    {
        return this->x;
    }

    /**
     * @brief Gets the multiplicative inverse of the current object.
     * @return The inverse value.
     */
    unsigned long long get_inverse()
    {
        return inverse(this->x);
    }

    /**
     * @brief Gets the value of the current object raised to the given power.
     * @return The x'th power of object.
     * @param x exponent.
     */
    Ring<N> pow(unsigned long long x)
    {
        unsigned long long exp = x;
        Ring<N> result(1);
        Ring<N> this_cpy(this->x);
        while (exp > 0)
        {
            if (exp % 2 == 1)
            {
                result = result * this_cpy;
            }
            this_cpy *= this_cpy;
            exp /= 2;
        }
        return result;
    }

    /**
     * @brief Gets the additive inverse of the current object.
     * @return The additive inverse value.
     */
    unsigned long long get_inverse_for_sums()
    {
        return inverse_for_sums(this->x);
    }

    Ring &operator=(unsigned long long new_x)
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

    // Friend functions to allow symmetric implicit conversions.
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

    bool operator==(const Ring &other)
    {
        return ((this->x % N) == (other.x % N));
    }
    bool operator!=(const Ring &other)
    {
        return ((this->x % N) != (other.x % N));
    }
    bool operator<(const Ring &other)
    {
        return ((this->x % N) < (other.x % N));
    }
    bool operator>(const Ring &other)
    {
        return ((this->x % N) > (other.x % N));
    }
    bool operator<=(const Ring &other)
    {
        return ((this->x % N) <= (other.x % N));
    }
    bool operator>=(const Ring &other)
    {
        return ((this->x % N) >= (other.x % N));
    }
    friend std::ostream &operator<<(std::ostream &os, const Ring &r)
    {
        return os << r.x;
    }
    friend std::istream &operator>>(std::istream &is, Ring &r)
    {
        unsigned long long tmp;
        if (is >> tmp)
            r.x = (tmp % N);
        return is;
    }
};
