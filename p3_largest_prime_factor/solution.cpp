#include <bits/stdc++.h>

// assumes n >= 2
std::vector<bool> sieve(long const n)
{
    std::vector<bool> is_prime(n + 1, true);
    is_prime[0U] = false;
    is_prime[1U] = false;
    for (size_t i{2}; i * i <= n; ++i)
    {
        if (is_prime[i])
        {
            for (size_t j{i * i}; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

int main()
{
    long n;
    std::cin >> n;
    std::cout << n << '\n';
    std::cout << "begin sieve\n";
    auto const is_prime{sieve(n)};
    std::cout << "end sieve\n";
    long max_prime_factor;
    for (long i{n}; i > 1; --i)
    {
        if (is_prime[i] && ((n % i) == 0))
        {
            max_prime_factor = i;
        }
    }
    std::cout << max_prime_factor << std::endl;
}