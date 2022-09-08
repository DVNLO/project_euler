#include <bits/stdc++.h>

std::string
mul(std::string digits, long const c)
{
    long carry{0};
    for (char &digit : digits)
    {
        long val{(digit - '0') * c + carry};
        digit = '0' + (val % 10);
        carry = val / 10;
    }
    while (carry > 0)
    {
        digits += '0' + (carry % 10);
        carry /= 10;
    }
    return digits;
}

long sum_digits(std::string n)
{
    long sum{0};
    for (auto const digit : n)
    {
        sum += digit - '0';
    }
    return sum;
}

std::string
reverse(std::string const &n)
{
    std::string ret{n};
    for (std::size_t i{0}; i < ret.size() / 2; ++i)
    {
        char tmp = ret[i];
        ret[i] = ret[ret.size() - i - 1];
        ret[ret.size() - i - 1] = tmp;
    }
    return ret;
}

int main()
{
    assert(mul("99", 9) == "198");
    assert(sum_digits(mul("99", 9)) == 18);

    std::string n{"1"};
    for (std::size_t i{0}; i < 1000; ++i)
    {
        n = mul(n, 2);
    }
    std::cout << reverse(n) << std::endl;
    std::cout << sum_digits(n) << std::endl;
}

// 10715086071862673209484250490600018105614048117055336074437503883703510511249361224931983788156958581275946729175531468251871452856923140435984577574698574803934567774824230985421074605062371141877954182153046474983581941267398767559165543946077062914571196477686542167660429831652624386837205668069376
// 10715086071862673209484250490600018105614048117055336074437503883703510511249361224931983788156958581275946729175531468251871452856923140435984577574698574803934567774824230985421074605062371141877954182153046474983581941267398767559165543946077062914571196477686542167660429831652624386837205668069376
