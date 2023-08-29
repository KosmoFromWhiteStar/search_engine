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
    std::vector<std::vector<int>> index_request(size_quer);
    for(int i = 0; i < size_quer; i++)
    {
        for(int j = 0; j < link_words[i].size();j++)
        {
            for(int k = 0; k < list.size(); k++)
            {
                if(list[k] == link_words[i][j])
                    index_request[i].push_back(k);
            }

        }
    }

    //word     //doc
    std::vector<std::vector<std::pair<size_t, int>>> doc_id(list.size());

    for(int i = 0; i < list.size(); i++)
    {
        for(int j = 0; j < _index.get_Word_Count(list[i]).size();j++)
        {
            doc_id[i].push_back
            ({
                    _index.get_Word_Count(list[i])[j].doc_id,
                    _index.get_Word_Count(list[i])[j].count
            });
        }
    }

    //Собирает по запросам
    //запрос   // документ
    std::vector<std::pair<size_t, int>> table;
    //
    std::vector<bool> request_add(size_quer);
    for(int i = 0; i < size_quer; i++)
    {
        request_add[i] = false;
    }
    //
    for(int i = 0; i < list.size(); i++)
    {
        for( int j = 0; j < doc_id[i].size(); j++ )
        {
            



        }
    }


    /////
    //Result
    int size_request = 4;
    std::vector<std::vector<Relative_Index>> result(size_quer);

    //

    //

    for(int i = 0; i < size_quer; i++)
    {
        if(table.empty())
        {
            continue;
        }
        int max = 0;
        for(int x = 0; i < table.size(); i++)
        {
            if(max < table[x].second)
            {
                max = table[x].second;
            }
        }
        for(int j = 0; j < table.size(); j++)
        {
            if(j > size_request)
            {
                break;
            }
            Relative_Index nw =
                    {
                        table[j].first,
                        (float)table[j].second/max
                    };
            result[i].push_back(nw);
        }
    }

    //Sort
    for(int i = 0; i < size_quer; i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            int sorted = j - 1;
            while(sorted > - 1 && result[i][sorted].rank < result[i][sorted + 1].rank)
            {
                std::swap(result[i][sorted], result[i][sorted + 1]);
                sorted--;
            }
        }

    }



    return result;
}
