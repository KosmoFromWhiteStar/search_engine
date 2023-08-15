//
// Created by The_K on 16.08.2023.
//

#ifndef SEARCH_ENGINE_CONVERTER_JSON_H
#define SEARCH_ENGINE_CONVERTER_JSON_H
#include <fstream>
#include <filesystem>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class Converter_JSON
{
private:
    json in_Put;
public:
    Converter_JSON() = default;
    Converter_JSON(std::string* path);

    void chek_result();
    void save_answere();

};


#endif //SEARCH_ENGINE_CONVERTER_JSON_H
