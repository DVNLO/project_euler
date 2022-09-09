#include <bits/stdc++.h>
/*

You are given the following information, but you may prefer to do some research for yourself.

    1 Jan 1900 was a Monday.
    Thirty days has September,
    April, June and November.
    All the rest have thirty-one,
    Saving February alone,
    Which has twenty-eight, rain or shine.
    And on leap years, twenty-nine.
    A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

*/

bool is_leap_year(uint32_t const year)
{
    bool const is_div_100{(year % 100) == 0};
    if (is_div_100)
    {
        bool const is_div_400{(year % 400) == 0};
        return is_div_400;
    }
    else
    {
        bool const is_div_4{(year % 4) == 0};
        return is_div_4;
    }
}

uint32_t get_days_per_month(uint32_t const year, uint32_t const month)
{
    constexpr std::array<uint32_t, 12 + 1> days_per_month = {
        31, // jan
        28, // feb
        31, // mar
        30, // apr
        31, // may
        30, // jun
        31, // jul
        31, // aug
        30, // sep
        31, // oct
        30, // nov
        31  // dec
    };
    uint32_t days_this_month{days_per_month[month - 1]};
    if ((month == 2) && is_leap_year(year))
    {
        ++days_this_month;
    }
    return days_this_month;
}

int main()
{
    constexpr uint32_t months_per_year{12};
    uint32_t first_of_month_sunday_count{0};
    uint32_t day_of_week{0}; // monday
    for (uint32_t year{1900}; year <= 2000; ++year)
    {
        for (uint32_t month{1}; month <= months_per_year; ++month)
        {
            uint32_t const days_this_month{get_days_per_month(year, month)};
            for (uint32_t day{1}; day <= days_this_month; ++day)
            {
                if ((year >= 1901) && (day == 1) && (day_of_week == 6))
                {
                    ++first_of_month_sunday_count;
                }
                ++day_of_week;
                if (day_of_week >= 7)
                {
                    day_of_week = 0;
                }
            }
        }
    }
    std::cout << first_of_month_sunday_count << std::endl;
}