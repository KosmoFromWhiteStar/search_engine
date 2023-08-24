//
// Created by The_K on 17.08.2023.
//
#include "../incl/Search_Server.h"


std::vector<std::vector<Relative_Index>> Search_Server::search(
        const std::vector<std::string>& queries_input)
{

    //Unic words
    std::vector<std::map<std::string, int>> unic_words;
    for (int i = 0; i < queries_input.size(); i++)
    {

        std::string temp_word = "";
        for(int j = 0; j < queries_input[i].length(); j++)
        {
            temp_word += queries_input[i][j];
            if(temp_word[temp_word.length()-1] == ' '
            || temp_word[temp_word.length()-1] == queries_input[i][j])
            {

                if (unic_words[i].count(temp_word) == 0)
                {
                    //Если нет слова тут добавляю
                    unic_words.push_back({std::make_pair(temp_word, 1)});
                }
                else {
                    unic_words[i].find(temp_word)->second++;
                }
            }

        }
    }
    std::cout<< "Here";
    //Sort word dont


    std::vector<std::vector<Relative_Index>> result;

    return result;
}
