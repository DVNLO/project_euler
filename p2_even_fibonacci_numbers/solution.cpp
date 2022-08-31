#include <bits/stdc++.h>
// find the sum of even fibonacci numbers less than 4 million
bool is_even(long const val)
{
    return !(val & 0x1);
}

int main()
{
    long sum{ 0 };
    long cur{ 2 };
    long pre{ 1 };
    while(cur < 4'000'000)
    {
        if(is_even(cur))
        {
            sum += cur;
        }
        long const nxt = pre + cur;
        pre = cur;
        cur = nxt;
    }
    std::cout << sum << std::endl;
}