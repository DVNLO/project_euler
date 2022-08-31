#include <bits/stdc++.h>
// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
// 232792560

// https://www.youtube.com/watch?v=JUzYl1TYMcU
long gcd(long a, long b)
{
    long r{a % b};
    while(r)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main()
{
    long long d{2};
    for (long long i{3}; i <= 20; ++i)
    {
        // finds the least common multiple of d and i
        d /= gcd(d, i);
        d *= i;
    }
    std::cout << d << std::endl;
}
