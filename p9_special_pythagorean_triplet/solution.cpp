#include <bits/stdc++.h>

// A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
// a2 + b2 = c2
//
// For example, 32 + 42 = 9 + 16 = 25 = 52.
//
// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product abc.
//
// know
// a2 + b2 = c2
// a < b < c
// a + b + c = 1000
// selecting a and b determines c
//
// c = 1000 - a - b
//
// b is greater than a
// a2 + b2 = (1000 - a - b)2
// (1000 - a - b)(1000 - a - b)
// 1000^2 - 1000a - 1000b -1000a + a^2 + ab - 1000b + ab + b^2
// 1000^2 - 2000a - 2000b + a^2 + 2ab + b^2
// a2 + b2 = 1000^2 - 2000a - 2000b + a^2 + 2ab + b^2
// 0 = 1000^2 - 2000a - 2000b + 2ab
// 2000a + 2000b - 2ab = 1000^2
// 2000a + b(2000 - 2a) = 1000^2
// 2000a + b(2000 - 2a) = (1000^2 - 2000a) / (2000 - 2a)
//
// b = (1000^2 - 2000a) / (2000 - 2a)
//
// a^2 + ((1000^2 - 2000a) / (2000 - 2a))^2 = (1000 - a - ((1000^2 - 2000a) / (2000 - 2a)))^2

int main()
{
    for (long a{1}; a < 1000; ++a)
    {
        long const b = (1000 * 1000 - 2000 * a) / (2000 - 2 * a);
        long const c = 1000 - a - b;
        if (a < b && b < c && ((a * a + b * b) == c * c))
        {
            std::cout << a * b * c << std::endl;
        }
    }
}
