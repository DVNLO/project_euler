#include <bits/stdc++.h>

// The sequence of triangle numbers is generated by adding the natural numbers.
//  So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:
//
//  1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
//
//  1  : 1
//  3  : 1 + 2
//  6  : 1 + 2 + 3
//  10 : 1 + 2 + 3 + 4
//  15 : 1 + 2 + 3 + 4 + 5
//  21 : 1 + 2 + 3 + 4 + 5 + 6
//
// Let us list the factors of the first seven triangle numbers:
//
//      1: 1
//      3: 1,3
//      6: 1,2,3,6
//     10: 1,2,5,10
//     15: 1,3,5,15
//     21: 1,3,7,21
//     28: 1,2,4,7,14,28
//
// We can see that 28 is the first triangle number to have over five divisors.
//
// What is the value of the first triangle number to have over five hundred divisors?

long div_count(long const n)
{
    if (n == 1)
    {
        return 1;
    }
    long ret{2};
    for (long i{2}; i * i < n; ++i)
    {
        if ((n % i) == 0)
        {
            ret += 2;
        }
    }
    return ret;
}

int main()
{
    long dc{0};
    long i{1};
    while (true)
    {
        long const n = (i * (i + 1)) / 2;
        dc = div_count(n);
        std::cout << i << ' ' << n << ' ' << dc << ' ' << std::endl;
        if (dc >= 500)
        {
            break;
        }
        ++i;
    }
}