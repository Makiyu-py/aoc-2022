#include <iostream>
#include <vector>
#include <set>
#include "../utils.hpp"

using namespace std;

int main()
{
    string input_text = aoc_utils::readFile("../inputs/04.txt");
    int assignment_pair_nums = 0;

    for (string pair : aoc_utils::split_string(input_text, "\n"))
    {
        vector<string> ranges = aoc_utils::split_string(pair, ",");
        vector<int> first_range = aoc_utils::stoi_vec_items(aoc_utils::split_string(ranges.at(0), "-"));
        vector<int> second_range = aoc_utils::stoi_vec_items(aoc_utils::split_string(ranges.at(1), "-"));

        set<int> first_range_expanded;
        set<int> second_range_expanded;

        for (size_t i = first_range.at(0); i < first_range.at(1) + 1; ++i)
        {
            first_range_expanded.insert(i);
        }
        for (size_t i = second_range.at(0); i < second_range.at(1) + 1; ++i)
        {
            second_range_expanded.insert(i);
        }

        if (  // checks if first range is a subset of the second range or vice versa
            includes(first_range_expanded.begin(), first_range_expanded.end(), second_range_expanded.begin(), second_range_expanded.end()) ||
            includes(second_range_expanded.begin(), second_range_expanded.end(), first_range_expanded.begin(), first_range_expanded.end())
        )
        {
            assignment_pair_nums++;
        }
    }
    cout << assignment_pair_nums << endl;
}