#include <iostream>
#include <vector>
#include <map>
#include "../utils.hpp"

using namespace std;

int main()
{
    string input_text = aoc_utils::readFile("../inputs/02.txt");
    vector<string> rounds = aoc_utils::split_string(input_text, "\n");

    map<string, int> choice_map {
        {"X", 1},
        {"Y", 2},
        {"Z", 3},
    };

    map<string, string> win_map {
        {"A", "Y"},
        {"B", "Z"},
        {"C", "X"},
    };
    map<string, string> draw_map {
        {"A", "X"},
        {"B", "Y"},
        {"C", "Z"},
    };
    map<string, string> loss_map {
        {"A", "Z"},
        {"B", "X"},
        {"C", "Y"},
    };


    int total_points = 0;

    for (string round : rounds)
    {
        vector<string> round_splitted = aoc_utils::split_string(round, " ");
        string opponent_played = round_splitted.at(0);
        string decision = round_splitted.at(1);

        if (decision == "Z")  // win
        {
            total_points += choice_map[win_map[opponent_played]];
            total_points += 6;
        }
        else if (decision == "X")  // loss
        {
            total_points += choice_map[loss_map[opponent_played]];
        }
        else  // if (decision == "Y")   // draw
        {
            total_points += choice_map[draw_map[opponent_played]];
            total_points += 3;
        }
    }

    cout << total_points << endl;
}