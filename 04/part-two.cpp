#include <iostream>
#include <vector>
#include <map>
#include "../utils.hpp"

using namespace std;

int main()
{
    string input_text = aoc_utils::readFile("../inputs/04.txt");
    int overlapping_pair_nums = 0;

    for (string pair : aoc_utils::split_string(input_text, "\n"))
    {
        // almost the same code except instead of set we're going to use vectors
        vector<string> ranges = aoc_utils::split_string(pair, ",");
        vector<int> first_range = aoc_utils::stoi_vec_items(aoc_utils::split_string(ranges.at(0), "-"));
        vector<int> second_range = aoc_utils::stoi_vec_items(aoc_utils::split_string(ranges.at(1), "-"));

        vector<int> first_range_expanded;
        vector<int> second_range_expanded;

        for (size_t i = first_range.at(0); i < first_range.at(1) + 1; ++i)
        {
            first_range_expanded.push_back(i);
        }
        for (size_t i = second_range.at(0); i < second_range.at(1) + 1; ++i)
        {
            second_range_expanded.push_back(i);
        }

        if (aoc_utils::get_intersection_between_two_vecs(first_range_expanded, second_range_expanded).size())
            overlapping_pair_nums++;
    }
    cout << overlapping_pair_nums << endl;
}