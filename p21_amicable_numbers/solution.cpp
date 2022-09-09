#include <bits/stdc++.h>
int main()
{
    constexpr size_t n{10'000};
    std::unordered_map<uint32_t, uint32_t> d;
    d[0] = UINT32_MAX;
    for (uint32_t i{1}; i < n; ++i)
    {
        uint32_t sum{0};
        for (uint32_t j{1}; j < i; ++j)
        {
            if (i % j == 0)
            {
                sum += j;
            }
        }
        d[i] = sum;
    }
    assert(d[284] == 220);
    assert(d[220] == 284);
    uint64_t amicable_num_sum{0};
    for (size_t a{1}; a < n; ++a)
    {
        auto const b = d[a];
        if (a != b && d[b] == a)
        {
            amicable_num_sum += a;
        }
    }
    std::cout << amicable_num_sum << std::endl;
}

/*
for (size_t a{2}; a < n; ++a)
    {
        auto const b = d[a];
        if (b < n && d[b] == a)
        {
            amicable_num_sum += a;
        }
    }

*/