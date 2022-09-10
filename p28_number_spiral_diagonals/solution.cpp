#include <bits/stdc++.h>

/*

Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is
formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?

*/

int64_t
sum_diagonals_spiral_matrix(int64_t const mat_dim)
{
    int64_t val{ 1 };
    int64_t sum{ val };
    uint64_t delta{ 2 };
    while(delta < mat_dim)
    {
        for(uint8_t i{ 0 }; i < 4; ++i)
        {
            val += delta;
            sum += val;
        }
        delta += 2;
    }
    return sum;
}

int
main()
{
    assert(sum_diagonals_spiral_matrix(5) == 101);
    std::cout << sum_diagonals_spiral_matrix(1001) << std::endl;
}