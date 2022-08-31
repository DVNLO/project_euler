#include <bits/stdc++.h>

// sieve approach times out; overkill
// assumes n >= 2
std::vector<bool> sieve(long const n)
{
    std::vector<bool> is_prime(n + 1, true);
    is_prime[0U] = false;
    is_prime[1U] = false;
    for (long i{2}; i * i <= n; ++i)
    {
        if (is_prime[i])
        {
            for (long j{i * i}; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

// trial division solution
int main()
{
    long n;
    std::cin >> n;
    std::cout << n << '\n';
    long d{1};
    while (n > 1)
    {
        ++d;
        while (((n % d) == 0))
        {
            n /= d;
        }
    }
    std::cout << d << std::endl;
}