#include <iostream>
#include <vector>
#include <map>
#include "../utils.hpp"

using namespace std;

int main()
{
    string input_text = aoc_utils::readFile("../inputs/02.txt");
    vector<string> rounds = aoc_utils::split_string(input_text, "\n");

    vector<string> win = { "A Y", "B Z", "C X" };
    vector<string> draw = { "A X", "B Y", "C Z" };

    map<string, int> choice_map {
        {"X", 1},
        {"Y", 2},
        {"Z", 3},
    };

    int total_points;

    for (string round : rounds)
    {
        string our_choice = aoc_utils::split_string(round, " ").at(1);
        total_points += choice_map[our_choice];

        if (aoc_utils::vec_contains(round, win))
        {
            total_points += 6;
        }
        else if (aoc_utils::vec_contains(round, draw))
        {
            total_points += 3;
        }
    }

    // help apparently it's too low?
    // i don't know how that came to be
    // it's literall
    cout << total_points << endl;
}