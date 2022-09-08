#include <bits/stdc++.h>

// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
// Find the sum of all the primes below two million.

std::vector<bool> sieve(long n)
{
    std::vector<bool> is_prime(n, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (long i{4}; i < n; i += 2) // i = 2*j = false for all j > 1
    {
        is_prime[i] = false;
    }
    for (long i{3}; i * i <= n; i += 2)
    {
        if (!is_prime[i])
        {
            continue;
        }
        for (long j{i + i}; j < n; j += i)
        {
            is_prime[j] = false;
        }
    }
    return is_prime;
}

int main()
{
    long long sum{0};
    auto const is_prime{sieve(2'000'000)};
    for (long i{0}; i < is_prime.size(); ++i)
    {
        if (is_prime[i])
        {
            // std::cout << i << ' ';
            assert(sum + i >= sum);
            sum += i;
        }
    }
    std::cout << sum << std::endl;
}
