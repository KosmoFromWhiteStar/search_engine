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
    void chek()
    {
     std::cout << json << std::endl;
    }
    int get_Response_Limit();
    void put_Answere(std::vector<std::pair<int, float>> answere);
};


#endif //SEARCH_ENGINE_CONVERTER_JSON_H
