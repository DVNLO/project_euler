#include <bits/stdc++.h>

long colatz(long n)
{
    return n & 0x1 ? 3 * n + 1 : n / 2;
}

int main()
{
    long max_chain_num{0};
    long max_chain_len{0};
    for (long i{1}; i < 100'000'000; ++i)
    {
        long chain_len{1};
        long j = i;
        while (j != 1)
        {
            j = colatz(j);
            ++chain_len;
        }
        if (chain_len > max_chain_len)
        {
            max_chain_len = chain_len;
            max_chain_num = i;
        }
    }
    std::cout << max_chain_num << std::endl;
}