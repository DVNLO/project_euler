#include <bits/stdc++.h>

std::string
get_max_repeated_substr(std::string s)
{
    std::string max_substr;
    auto const s_sz{s.size()};
    for (size_t i{1}; i < s_sz; ++i)
    {
        for (size_t j{0}; j < i; ++j)
        {
            std::string substr;
            size_t k{0};
            while (j + k < i && i + k < s_sz && s[j + k] == s[i + k])
            {
                substr += s[j + k];
                ++k;
            }
            if (substr.size() > max_substr.size())
            {
                max_substr = substr;
            }
        }
    }
    return max_substr;
}

std::string
get_recprocial_tail(int64_t const d, size_t const p)
{
    int64_t n{1};
    std::string ret;
    for (size_t i{0}; i < p; ++i)
    {
        if (n < d)
        {
            n *= 10;
        }
        int64_t const q{n / d};
        ret += std::to_string(q);
        n -= q * d;
        if (n <= 0)
        {
            break;
        }
    }
    return ret;
}

int main()
{
    assert(get_max_repeated_substr("xyyellowyellow") == "yellow");
    assert(get_max_repeated_substr("abaxyzaba") == "aba");
    assert(get_max_repeated_substr("a") == "");
    assert(get_max_repeated_substr("abc") == "");
    assert(get_max_repeated_substr("142857142857142") == "142857");
    for (int64_t d{2}; d < 1000; ++d)
    {
        auto const tail{get_recprocial_tail(d, 100)};
        auto const max_repeated_ss{get_max_repeated_substr(tail)};
        std::cout << d << ' ' << tail << '\n'
                  << max_repeated_ss << "\n\n";
    }
    std::cout << std::endl;
}
