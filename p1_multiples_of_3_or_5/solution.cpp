#include <bits/stdc++.h>
// note we can compute the value directly by
// 3 * sum(1,1000/3, 1) + 5 * sum(1, 1000/5 - 1, 1) - 15 * sum(1, 1000/15, 1)
// where the divisions are floored and sum(...) can be substituted with the 
// sum of a consecutive sequence between 1 and n (1, 2, 3, ... , n) with n*(n+1)/2
// the formula is then
// 3(333*334/2) + 5(199*200/2) - 15(66*67/2) = 233168
int main()
{
    long sum{ 0 };
    for(long n{ 3 }; n < 1000; ++n)
    {
        bool const is_div_3{ (n % 3) == 0};
        bool const is_div_5{ (n % 5) == 0};
        if(is_div_3 || is_div_5)
        {
            sum += n;
        }
    }
    std::cout << sum << std::endl;
}
