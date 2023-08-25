//
// Created by The_K on 17.08.2023.
//
#include "../incl/Inverted_Index.h"

void Inverted_Index::update_Document_Base(std::vector<std::string> text) {
    if (!state) {
        std::cerr << "Err" << std::endl;
        return;
    }
    //
    std::string word = "";
    auto fu = [&](int current_file = 0) {

        //for catch last word
        text[current_file] += " ";
        for (int i = 0; i < text[current_file].length(); i++)
        {
            //build word
            word += text[current_file][i];

            if (word[word.length() - 1] == ' ')
            {
                //Clear word
                word.erase(word.find(' '), 1);

                //add word to dictionary
                if (freq_dictionary.count(word) == 0) {
                    std::vector<Entry> temp = {{(size_t) current_file, 1}};
                    freq_dictionary.insert(std::make_pair(word, temp));
                } else
                {
                    bool cheked = false;
                    for(int k = 0; k < freq_dictionary.find(word)->second.size(); k++) {
                        if (freq_dictionary.find(word)->second[k].doc_id == current_file)
                        {
                            freq_dictionary.find(word)->second[k].count++;
                            cheked = true;
                            break;
                        }
                    }
                    if(!cheked)freq_dictionary.find(word)->second.push_back({(size_t)current_file, 1});

                }
                word = "";
            }
        }
    };

    //Here will be thread
    for(int i = 0; i < text.size(); i++)
    {
        fu(i);
    }
    //
}

std::vector<Entry> Inverted_Index::get_Word_Count(const std::string &word)
{
    if(!state){
        std::cerr << "Err" << std::endl;
        return std::vector<Entry>({});
    }
    if(freq_dictionary.count(word) == 0)
    {
        return std::vector<Entry>({});
    }
    return freq_dictionary.find(word)->second;
}
