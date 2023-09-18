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
    //Контроль состояния потоков и контроль выхода за предел
    std::vector<std::atomic<bool>> done(std::thread::hardware_concurrency());
    for(int i = 0; i < done.size(); i++)
    {
        done[i] = true;
    }
    //Лямбда функция для индексировангия
    auto fu = [&](int index_done, int current_file = 0) {
        done[index_done] = false;
        //for catch last word
        text[current_file] += " ";
        for (int i = 0; i < text[current_file].length(); i++)
        {
            //build word
            word += text[current_file][i];

            if (word[word.length() - 1] == ' ')
            {
                //Clear word
                std::string temp = "";
                for(int l = 0; l < word.length(); l++)
                {
                    if(word[l] != ' ')
                    {
                        temp += word[l];
                    }
                }
                word = temp;

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
        //Clear thread
        done[index_done] = true;
    };
    //Вектор потоков (многопоточность)
    std::vector<std::thread*> flows(std::thread::hardware_concurrency());
    //Открытие нового потока
    for(int i = 0; i < text.size(); i++)
    {
        bool next = false;
        do{
            for(int j = 0; j < done.size(); j++)
            {
                if(done[j])
                {
                    if(flows[j] != NULL) flows[j]->join();
                    next = true;
                    flows[j] = new std::thread( fu, j , i );
                    break;
                }
            }
        }while(!next);
    }
    //Закрытие потоков
    for(int i = 0; i < flows.size(); i++)
    {
        if(flows[i] != nullptr) {
            flows[i]->join();
            flows[i] = nullptr;
        }
        if(std::thread::hardware_concurrency() > text.size() && i > text.size())
        {
            return;
        }
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
