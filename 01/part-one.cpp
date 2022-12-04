#include <iostream>
#include <vector>
#include "../utils.hpp"

using namespace std;

int main()
{
    string input_text = aoc_utils::readFile("../inputs/01.txt");
    vector<string> calories_vec = aoc_utils::split_string(input_text, "\n\n");

    // sum all calories on the vector to another one
    vector<int> total_calories_each;
    for (string i : calories_vec)
    {
        vector<string> i_calories = aoc_utils::split_string(i, "\n");
        int i_calories_sum = 0;  // tip to self: don't leave stuff in a for-loop uninitialized

        for (string i_cal : i_calories)
        {
            if (!i_cal.empty())
                i_calories_sum += stoi(i_cal);
        }

        total_calories_each.push_back(i_calories_sum);
    }

    cout << "All total calories:" << endl;
    for (int i : total_calories_each)
    {
        cout << i << endl;
    }

    int highest_calories = *max_element(total_calories_each.begin(), total_calories_each.end());
    cout << "\nHighest Total: ";
    cout << highest_calories << endl;
}