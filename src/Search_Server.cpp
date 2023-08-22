//
// Created by The_K on 17.08.2023.
//
#include "../incl/Search_Server.h"


std::vector<std::vector<Relative_Index>> Search_Server::search(
        const std::vector<std::string>& queries_input)
{
    //Create list unic words
    std::vector<std::string> unicue_word;
    for(int u = 0; u < queries_input.size(); u++)
    {
        bool repeat_word = false;
        for(int k = 0; k < unicue_word.size(); k++)
        {
            if (queries_input[k] == unicue_word[k])
            {
                repeat_word = true;
            }
        }
        if(!repeat_word) unicue_word.push_back(queries_input[u]);
    }

    ///Sort list
    std::vector<int> sum{}; //index sum = index unicue_word
    for(int i = 0; i < unicue_word.size();i++)
    {
        int min_sum = 0;
        for (int c = 0; c < _index.get_Word_Count(unicue_word[i]).size(); c++)
        {
            min_sum += _index.get_Word_Count(queries_input[i])[c].count;
        }
        sum.push_back(min_sum);
    }
}
