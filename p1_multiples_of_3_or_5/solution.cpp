#include <bits/stdc++.h>
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
