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

    for (string rucksack : aoc_utils::split_string(input_text, "\n"))
    {   
        string compartment_one = rucksack.substr(0, rucksack.length()/2);
        string compartment_two = rucksack.substr(rucksack.length()/2);

        vector<char> compartment_one_vec_of_chars(compartment_one.begin(), compartment_one.end());
        vector<char> compartment_two_vec_of_chars(compartment_two.begin(), compartment_two.end());
        compartment_one_vec_of_chars = aoc_utils::remove_vec_dupes(compartment_one_vec_of_chars);
        compartment_two_vec_of_chars = aoc_utils::remove_vec_dupes(compartment_two_vec_of_chars);

        // for (vector<char> vec : {compartment_one_vec_of_chars, compartment_two_vec_of_chars})
        // {
        //     cout << "{ ";
        //     for (char i : vec)
        //     {
        //         cout << i << ", ";
        //     }
        //     cout << "}" << endl;
        // }

        vector<char> intersection = aoc_utils::get_intersection_between_two_vecs(
            compartment_one_vec_of_chars,
            compartment_two_vec_of_chars
        );

        // possible bug, if intersection is more than one, the priority map thing wouldn't work
        // but who cares it's not like they have rucksacks with more than 1 item type
        string item_type(intersection.begin(), intersection.end());
        // cout << item_type << endl << endl;

        try
        {
            priority_sum += priority_map[item_type];
        }
        catch(const std::exception& e)
        {
            // i dont trust my own words (from last comment)
            std::cerr << "Item type: " << item_type << endl;
            throw e;
        }
        
    }

    cout << priority_sum << endl;
}