#include <bits/stdc++.h>
int main()
{
    std::vector<long> primes{2, 3, 5, 7, 11, 13, 17, 19, 23};
    primes.reserve(10'001);
    long n{23};
    while (primes.size() < 10'001)
    {
        n += 2;
        bool is_prime{true};
        for (auto const prime : primes)
        {
            if ((n % prime) == 0)
            {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
        {
            primes.emplace_back(n);
        }
    }
    std::cout << n << std::endl;
}