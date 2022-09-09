#include <bits/stdc++.h>
/*



A perfect number is a number for which the sum of its proper divisors is exactly equal to the number.
For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n
and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24.

By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers.
However, this upper limit cannot be reduced any further by analysis even though it is known that
the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

sum_divs(n) < n ==> n is deficient
sum_divs(n) > n ==> n is abundant
sum_divs(n) == n ==> n is perfect

sum all + ints which cannot be written as the sum of two abundant numbers
i is abundant
j is abundant
k = i + j is the sum of two abundant numbers


discover all abundant numbers less than 28123
find all k
any which cannot be summed are therefore not writeable as sum of abundant numbers
*/

// assumes num > 1
std::vector<int64_t>
get_proper_divs(int64_t const num)
{
    std::vector<int64_t> divs;
    divs.emplace_back(1);
    for (int64_t i{2}; i * i <= num; ++i)
    {
        if (num % i == 0)
        {
            divs.emplace_back(i);
            // skip squares to avoid double counting
            if (i * i < num)
            {
                divs.emplace_back(num / i);
            }
        }
    }
    return divs;
}

int64_t get_sum(std::vector<int64_t> const &nums)
{
    int64_t sum{0};
    for (auto const num : nums)
    {
        sum += num;
    }
    return sum;
}

void test_proper_divs()
{
    {
        std::vector<int64_t> divs_28_expected{1, 2, 4, 7, 14};
        auto divs_28_actual{get_proper_divs(28)};
        std::sort(std::begin(divs_28_actual), std::end(divs_28_actual));
        assert(divs_28_actual == divs_28_expected);
    }

    {
        std::vector<int64_t> divs_8_expected{1, 2, 4};
        auto divs_8_actual{get_proper_divs(8)};
        std::sort(std::begin(divs_8_actual), std::end(divs_8_actual));
        assert(divs_8_actual == divs_8_expected);
    }

    {
        std::vector<int64_t> divs_16_expected{1, 2, 4, 8};
        auto divs_16_actual{get_proper_divs(16)};
        std::sort(std::begin(divs_16_actual), std::end(divs_16_actual));
        assert(divs_16_actual == divs_16_expected);
    }
}

int main()
{
    test_proper_divs();

    int64_t abn_limit{28123}; // abundant number limit
    std::vector<int64_t> abundant_nums;
    for (int64_t i{2}; i <= abn_limit; ++i)
    {
        auto const divs{get_proper_divs(i)};
        auto const sum_divs{get_sum(divs)};
        if (sum_divs > i)
        {
            abundant_nums.emplace_back(i);
        }
    }
    std::unordered_set<int64_t> sum_abundant_nums;
    auto const abundant_num_count{abundant_nums.size()};
    sum_abundant_nums.reserve(abundant_num_count * abundant_num_count);
    for (size_t i{0U}; i < abundant_num_count; ++i)
    {
        for (size_t j{i}; j < abundant_num_count; ++j)
        {
            auto const sum_abundant_num{abundant_nums[i] + abundant_nums[j]};
            sum_abundant_nums.insert(sum_abundant_num);
        }
    }
    assert(sum_abundant_nums.count(24));
    int64_t cannot_be_written_as_sum_abn_num_sum{0};
    for (int64_t i{1U}; i <= abn_limit; ++i)
    {
        if (!sum_abundant_nums.count(i))
        {
            cannot_be_written_as_sum_abn_num_sum += i;
        }
    }
    std::cout << cannot_be_written_as_sum_abn_num_sum << std::endl;
}