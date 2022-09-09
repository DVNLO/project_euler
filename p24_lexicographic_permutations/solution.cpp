#include <bits/stdc++.h>

void get_permutations(std::vector<std::string> &permutations,
                      std::string &permutation,
                      std::string const &str)
{
    if (!str.size())
    {
        permutations.emplace_back(permutation);
        return;
    }
    for (size_t i{0}; i < str.size(); ++i)
    {
        permutation += str[i];
        std::string remain_str{str};
        remain_str.erase(i, 1);
        get_permutations(permutations, permutation, remain_str);
        permutation.pop_back();
    }
}

std::vector<std::string> get_permutations(std::string const &str)
{
    std::vector<std::string> permutations;
    std::string permutation;
    get_permutations(permutations, permutation, str);
    return permutations;
}

void test_permutation_012()
{
    std::vector<std::string> expected_permutations{
        "012", "021", "102", "120", "201", "210"};
    std::string str{"012"};
    auto const actual_permutations{get_permutations(str)};
    for (auto const &str : actual_permutations)
    {
        std::cout << str << ' ';
    }
    std::cout << std::endl;
    assert(expected_permutations == actual_permutations);
}

int main()
{
    test_permutation_012();
    auto const perms{get_permutations("0123456789")};
    std::cout << perms[999'999] << std::endl;
}