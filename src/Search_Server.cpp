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
    std::vector<std::vector<int>> index_request(size_quer);

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

    //Собирает по запросам
    std::vector<std::vector<std::pair<size_t, int>>> table(size_quer);

    for(int i = 0; i < list.size(); i++)
    {
        for(int k = 0; k < size_quer; k++)
        {
            std::vector<std::pair<size_t, int>> tab_res;
            for(int z = 0; z < index_request[k].size(); z++)
            {
                for(int j = 0; j < doc_id[index_request[k][z]].size(); j++)
                {
                    if(tab_res.empty())
                    {
                        tab_res.push_back(
                            {
                                doc_id[index_request[k][z]][j].first,
                                doc_id[index_request[k][z]][j].second
                            });
                            continue;
                    }
                    bool find = false;
                    for(int x = 0; x < tab_res.size(); x++)
                    {
                        if(doc_id[index_request[k][z]][j].first == tab_res[x].first)
                        {
                            tab_res[x].second += doc_id[index_request[k][z]][j].second;
                            find = true;
                        }
                    }
                    if(!find)
                    {
                        tab_res.push_back(
                        {
                            doc_id[index_request[k][z]][j].first,
                            doc_id[index_request[k][z]][j].second
                        });
                    }
                }
            }
            table[k] = tab_res;
        }
    }

    //Result
    int size_request = 4;
    std::vector<std::vector<Relative_Index>> result(size_quer);
    //
    for(int i = 0; i < size_quer; i++)
    {
        if(table[i].empty())
        {
            continue;
        }
        
        int max = 0;
        for(int x = 0; x < table[i].size(); x++)
        {
            if(max < table[i][x].second)
            {
                max = table[i][x].second;
            }
        }
        
        for(int j = 0; j < table[i].size(); j++)
        {
            if(j > size_request)
            {
                break;
            }          
            result[i].push_back(
                {
                    table[i][j].first,
                    (float)table[i][j].second/max
                });
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
