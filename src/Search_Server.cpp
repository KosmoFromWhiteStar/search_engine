//
// Created by The_K on 17.08.2023.
//
#include "../incl/Search_Server.h"


std::vector<std::vector<Relative_Index>> Search_Server::search(
        const std::vector<std::string>& queries_input)
{
    const int size_quer = queries_input.size();
    std::map<std::string, int> unic_words;
    std::vector<std::string> list;
    std::vector< std::vector < std::string > > link_words(size_quer);


    //Unic words and Search in files
    for (int i = 0; i < size_quer; i++)
    {
        std::string temp_str = "";
        //
        for(int j = 0; j < queries_input[i].length(); j++)
        {
            temp_str += queries_input[i][j];
            if(j + 1 == queries_input[i].length())
            {
                temp_str += ' ';
            }
            if(temp_str[temp_str.length() - 1] == ' ')
            {
                temp_str.erase(temp_str.find(' '), 1);
                if(unic_words.count(temp_str) == 0)
                {
                    int sum = 0;
                    for(int k = 0; k < _index.get_Word_Count(temp_str).size(); k++)
                    {
                        sum += _index.get_Word_Count(temp_str)[k].count;
                    }

                    list.push_back(temp_str);
                    link_words[i].push_back({temp_str});
                    unic_words.insert(std::make_pair(temp_str, sum));
                }
                temp_str = "";
            }
        }
        ///
    }

    //Sort by increasing
    for (int j = 0; j < list.size(); j++)
    {
        int sorted = j - 1;
        while(sorted > - 1 && unic_words.find(list[sorted])->second > unic_words.find(list[sorted+1])->second)
        {
            std::swap(list[sorted], list[sorted+1]);
            sorted--;
        }
    }
    //////

    //word     //doc
    std::vector<std::vector<size_t>> doc_id(list.size());
    std::vector<std::vector<int>> abs_rel(list.size());
    //
    for(int i = 0; i < list.size(); i++)
    {
        if(_index.get_Word_Count(list[i]).empty())
        {
            doc_id[i].push_back(0);
            abs_rel[i].push_back(0);
        }
        for(int j = 0; j < _index.get_Word_Count(list[i]).size();j++)
        {
            doc_id[i].push_back(_index.get_Word_Count(list[i])[j].doc_id);
            abs_rel[i].push_back(_index.get_Word_Count(list[i])[j].count);
        }
    }
    //
    std::vector<std::vector<int>> rel;
    for(int i = 0; i < list.size(); i++)
    {


    }

    /////
    //Result
    int size_request = 5;
    std::vector<std::vector<Relative_Index>> result(size_quer);


    return result;
}
