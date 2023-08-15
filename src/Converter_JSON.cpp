//
// Created by The_K on 16.08.2023.
//
#include <iostream>
#include "../incl/Converter_JSON.h"

Converter_JSON::Converter_JSON(std::string* path)
{
    std::ifstream file;
    file.open(*path);
    file >> in_Put;
    file.close();
}

void Converter_JSON::chek_result() {
    std::cout << in_Put << std::endl;
}
