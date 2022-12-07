#include <iostream>
#include <vector>
#include <map>
#include "../utils.hpp"

using namespace std;

int main()
{
    string input_text = aoc_utils::readFile("../inputs/03.txt");

    map<string, int> priority_map = {
        {"a", 1}, {"b", 2}, {"c", 3}, {"d", 4}, {"e", 5},
        {"f", 6}, {"g", 7}, {"h", 8}, {"i", 9}, {"j", 10},
        {"k", 11}, {"l", 12}, {"m", 13}, {"n", 14}, {"o", 15},
        {"p", 16}, {"q", 17}, {"r", 18}, {"s", 19}, {"t", 20},
        {"u", 21}, {"v", 22}, {"w", 23}, {"x", 24}, {"y", 25},
        {"z", 26}, {"A", 27}, {"B", 28}, {"C", 29}, {"D", 30},
        {"E", 31}, {"F", 32}, {"G", 33}, {"H", 34}, {"I", 35},
        {"J", 36}, {"K", 37}, {"L", 38}, {"M", 39}, {"N", 40},
        {"O", 41}, {"P", 42}, {"Q", 43}, {"R", 44}, {"S", 45},
        {"T", 46}, {"U", 47}, {"V", 48}, {"W", 49}, {"X", 50},
        {"Y", 51}, {"Z", 52}
    };
    int priority_sum = 0;
    vector<string> rucksacks = aoc_utils::split_string(input_text, "\n");

    for (size_t index = 0; index < 301; index += 3)
    {
        // group
        string rucksack1 = rucksacks[index];
        string rucksack2 = rucksacks[index + 1];
        string rucksack3 = rucksacks[index + 2];

        vector<char> rucksack1_vec_of_chars(rucksack1.begin(), rucksack1.end());
        rucksack1_vec_of_chars = aoc_utils::remove_vec_dupes(rucksack1_vec_of_chars);
        
        vector<char> rucksack2_vec_of_chars(rucksack2.begin(), rucksack2.end());
        rucksack2_vec_of_chars = aoc_utils::remove_vec_dupes(rucksack2_vec_of_chars);
        
        vector<char> rucksack3_vec_of_chars(rucksack3.begin(), rucksack3.end());
        rucksack3_vec_of_chars = aoc_utils::remove_vec_dupes(rucksack3_vec_of_chars);


        vector<char> intersection = aoc_utils::get_intersection_between_two_vecs(
            aoc_utils::get_intersection_between_two_vecs(
                rucksack1_vec_of_chars,
                rucksack2_vec_of_chars
            ),
            rucksack3_vec_of_chars
        );

        string item_type(intersection.begin(), intersection.end());

        priority_sum += priority_map[item_type];
    }
    cout << priority_sum << endl;
}