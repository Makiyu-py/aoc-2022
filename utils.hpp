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
        string throwaway = to_split;
        vector<string> out;

        size_t pos = 0;
        string token;
        while ((pos = throwaway.find(delim)) != string::npos) {
            token = throwaway.substr(0, pos);
            out.push_back(token);
            throwaway.erase(0, pos + delim.length());
        }
        // last item is out of the loop and becomes throwaway (aka to_split)
        if (!throwaway.empty())
            out.push_back(throwaway);

        return out;
    }
    template <typename T>
    bool vec_contains(T item, vector<T> vec)
    {
        return any_of(vec.begin(), vec.end(), [&](const T& elem) { return elem == item; });
    }
    template <typename T>
    vector<T> remove_vec_dupes(vector<T> vec)
    {
        vector<T> new_vec = vec;
        sort( new_vec.begin(), new_vec.end() );
        new_vec.erase( unique( new_vec.begin(), new_vec.end() ), new_vec.end() );

        return new_vec;
    }
    template <typename T>
    vector<T> get_intersection_between_two_vecs(vector<T> vector1, vector<T> vector2)
    {
        vector<T> common_elements;
    
        set_intersection(
            vector1.begin(),
            vector1.end(),
            vector2.begin(),
            vector2.end(),
            back_inserter(common_elements)
        );
        
        return common_elements;
    }
}