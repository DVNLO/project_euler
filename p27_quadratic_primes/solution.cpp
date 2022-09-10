#include <bits/stdc++.h>

/*
Considering quadratics of the form:
n^2 + an + b
, where
-1000 < a < 1000
and
-1000 <= b <= 1000


where
is the modulus/absolute value of
e.g. and

Find the product of the coefficients,
a and b for the quadratic expression
that produces the maximum number of
primes for consecutive values of n,
 starting with n = 0.
*/

namespace primes
{
    std::unordered_set<int64_t> primes;

    bool is_prime(int64_t const n)
    {
        if (n < 2)
        {
            return false;
        }
        if (primes.count(n))
        {
            return true;
        }
        for (int64_t i{2}; i * i <= n; ++i)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        primes.insert(n); // amortize prime discovery
        return true;
    }
}

void test_is_prime()
{
    std::unordered_set<int64_t> expected_primes{
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
        43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    for (int64_t i{0}; i <= 100; ++i)
    {
        if (primes::is_prime(i))
        {
            assert(expected_primes.count(i));
        }
    }
}

int64_t get_consecutive_quad_prime_count(int64_t const a, int64_t const b)
{
    int64_t n{0};
    int64_t y{n * n + a * n + b};
    while (primes::is_prime(y))
    {
        ++n;
        y = n * n + a * n + b;
    }
    return n;
}

int main()
{
    test_is_prime();
    assert(get_consecutive_quad_prime_count(1, 41) == 40);
    assert(get_consecutive_quad_prime_count(-79, 1601) == 80);

    int64_t max_prod;
    int64_t max_prime_count{0};
    for (int64_t a{-999}; a < 1000; ++a)
    {
        for (int64_t b{-1000}; b <= 1000; ++b)
        {
            int64_t const n{get_consecutive_quad_prime_count(a, b)};
            if (n > max_prime_count)
            {
                max_prime_count = n;
                max_prod = a * b;
                std::cout << a << ' ' << b << ' ' << max_prod << ' ' << n << std::endl;
            }
        }
    }
}