#include <bits/stdc++.h>
// A palindromic number reads the same both ways. The largest palindrome made
// from the product of two 2-digit numbers is 9009 = 91 × 99.
// Find the largest palindrome made from the product of two 3-digit numbers.
bool is_palindrome(long const n)
{
    long l = n;
    long r = 0;
    while (l > r)
    {
        r *= 10;
        r += l % 10;
        l /= 10;
    }
    return r < 10 || l == r;
}

int main()
{
    long max_p{0};
    for (long l{999}; l >= 100; --l)    // search from max -> min
    {
        for (long r{999}; r >= l; --r)  // search from max -> min while r >= l
        {
            long const p{l * r};
            if (is_palindrome(p))
            {
                if (p > max_p)
                {
                    max_p = p;
                }
                else
                {
                    break; // max_p discovered
                }
            }
        }
    }
    std::cout << max_p << std::endl;
}