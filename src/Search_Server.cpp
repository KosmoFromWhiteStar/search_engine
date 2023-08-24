//
// Created by The_K on 17.08.2023.
//
#include "../incl/Search_Server.h"


std::vector<std::vector<Relative_Index>> Search_Server::search(
        const std::vector<std::string>& queries_input)
{
    //Unic words
    std::vector<std::string> unic_words;
    for(int i = 0; i < queries_input.size(); i++)
    {
        bool find_word = false;
        for(int k = 0; k < unic_words.size(); k++)
        {
            if(unic_words[k] == queries_input[i]) find_word = true;
        }
        if(!find_word) unic_words.push_back(queries_input[i]);
    }

    //Sort
    std::map<std::string, int> temp_list;
    for(int i = 0; i < unic_words.size(); i++)
    {
        std::vector<Entry> temp_vec = _index.get_Word_Count(unic_words[i]);
        for(int k = 0; k < temp_vec.size(); k++)
        {
            if(temp_list.count(unic_words[i]) == 0)
            {
                temp_list.insert(std::make_pair(unic_words[i], 0));
            }
            temp_list.find(unic_words[i])->second += temp_vec[k].count;
        }
    }






    std::vector<std::vector<Relative_Index>> result;

    return result;
}
