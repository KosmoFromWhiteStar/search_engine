//
// Created by The_K on 16.08.2023.
//
#ifndef SEARCH_ENGINE_CONVERTER_JSON_H
#define SEARCH_ENGINE_CONVERTER_JSON_H
#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <filesystem>
#include "nlohmann/json.hpp"

#define VERSION "1"

#define TRUE "\"true\",\n"
#define FALSE "\"false\"\n}"
#define DOC_ID "\"doc_id\" : "
#define RANK  ", \"rank\" : "
#define LINE(s) std::cout << "========[\t" << s << "\t]========" << std::endl

using js = nlohmann::json;
class Converter_JSON
{
private:
    js json;
    //state of search engine
    bool state = false;

public:
    Converter_JSON();
    void start();
    std::vector<std::string> get_Text_Document();
    int get_Response_Limit();
    std::vector<std::string> get_Request();
    void put_Answere(std::vector<std::vector<std::pair<int, float>>> answere);
};


#endif //SEARCH_ENGINE_CONVERTER_JSON_H
