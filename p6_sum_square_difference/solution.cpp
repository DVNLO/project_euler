#include <bits/stdc++.h>

// the O(1) solution uses the explicit formulas for the sum
// n consecutive numbers and the sum of n consecutive squares
// if you can't recall, https://www.wolframalpha.com/input?i=sum+i+%3D+1+to+n+of+i%5E2
long sum_square_diff(long const n)
{
    long sum{n * (n + 1) / 2};
    long sum_sq{n * (n + 1) * (2 * n + 1) / 6};
    return sum * sum - sum_sq;
}

long sum_square_diff_naieve(long const n)
{
    long sum{0};    // sum
    long sum_sq{0}; // sum of square
    for (long i{1}; i <= n; ++i)
    {
        sum += i;
        sum_sq += i * i;
    }
    return sum * sum - sum_sq;
}

int main()
{
    long n;
    std::cin >> n;
    std::cout << sum_square_diff(n) << std::endl;
    std::cout << sum_square_diff_naieve(n) << std::endl;
}