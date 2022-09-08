#include <bits/stdc++.h>

long num_ways_walk_grid(long const begin_row_idx, long const begin_col_idx,
                        long const row_count, long const col_count)
{
    std::vector<long> way_counts(col_count, 1);
    for (long r{begin_row_idx}; r < row_count; ++r)
    {
        long left_count{1};
        for (long c{begin_col_idx}; c < col_count; ++c)
        {
            long &up_count{way_counts[c]};
            long const cur_count{left_count + up_count};
            left_count = cur_count;
            up_count = cur_count;
        }
    }
    return way_counts[col_count - 1];
}

int main()
{
    std::cout << num_ways_walk_grid(0, 0, 20, 20) << std::endl;
}
// 137846528820
// 137'846'528'820