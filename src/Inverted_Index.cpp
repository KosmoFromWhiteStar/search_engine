//
// Created by The_K on 17.08.2023.
//
#include "../incl/Inverted_Index.h"

Inverted_Index::Inverted_Index(Converter_JSON* in_json)
    : json(in_json)
{
    if(in_json == nullptr)
    {
        return;
    }
    state = true;
}

void Inverted_Index::update_Document_Base(std::vector<std::string> text)
{
    if(!state){
        std::cerr << "Err" << std::endl;
        return;
    }
    //
}

std::vector<Entry> Inverted_Index::get_Word_Count(const std::string &word)
{
    if(!state){
        std::cerr << "Err" << std::endl;
        return std::vector<Entry>();
    }
    return freq_dictionary.find(word)->second;
}
