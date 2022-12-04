#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

namespace aoc_utils
{
    string readFile(string fn)
    {
        ifstream file;
        file.open(filesystem::canonical(fn));

        stringstream outstring;
        string line;
        while (getline(file, line))
        {
            outstring << line << '\n';
        }

        file.close();

        return outstring.str();
    }
    vector<string> split_string(string &to_split, string delim)
    {
        vector<string> out;

        size_t pos = 0;
        string token;
        while ((pos = to_split.find(delim)) != std::string::npos) {
            token = to_split.substr(0, pos);
            out.push_back(token);
            to_split.erase(0, pos + delim.length());
        }
        // last item is out of the loop and becomes to_split
        if (!to_split.empty())
            out.push_back(to_split);

        return out;
    }
    template <typename T>
    bool vec_contains(T item, vector<T> vec)
    {
        return any_of(vec.begin(), vec.end(), [&](const T& elem) { return elem == item; });
    }
}