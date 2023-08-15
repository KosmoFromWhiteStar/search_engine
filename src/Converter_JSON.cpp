//
// Created by The_K on 16.08.2023.
//
#include <iostream>
#include "../incl/Converter_JSON.h"
#include <cassert>

Converter_JSON::Converter_JSON(std::string* path)
{
    std::ifstream file;
    if(!file.is_open())
    {
        std::cout << "File input isnt open" << std::endl;
    }
    file.open(*path);
    file >> in_Put;
    file.close();
}

void Converter_JSON::chek_result() {
    std::cout << in_Put << std::endl;
}

void Converter_JSON::save_answere() {
    std::ofstream output("answers.json");
    if(!output.is_open())
    {
        std::cout << "File output isnt open" << std::endl;
    }
    output << in_Put;

    output.close();
}
