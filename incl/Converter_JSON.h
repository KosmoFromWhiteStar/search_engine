//
// Created by The_K on 16.08.2023.
//

#ifndef SEARCH_ENGINE_CONVERTER_JSON_H
#define SEARCH_ENGINE_CONVERTER_JSON_H
#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include "nlohmann/json.hpp"

#define VERSION 1

using js = nlohmann::json;
class Converter_JSON
{
private:
    //state of search engine
    bool state = false;
    js json;
public:
    Converter_JSON();
    void start();
    void save_answere();
    int GetResponseLimit();
    void put_Answere(std::vector<std::pair<int, float>> answere);
};


#endif //SEARCH_ENGINE_CONVERTER_JSON_H
