//
// Created by The_K on 16.08.2023.
//

#include "../incl/Converter_JSON.h"
#include <cassert>

#define LINE(s) std::cout << "========[" << s << "]========" << std::endl

Converter_JSON::Converter_JSON()
{
    std::ifstream file;
    file.open("..//..//config.json");
    //
    if(!(file.is_open()))
    {
        std::cerr << "Config file is missing" << std::endl;
        return;
    }
    file >> json;
    if(json["config"] == nullptr)
    {
        std::cerr << "Config is empty" << std::endl;
        return;
    }
    if(json["config"]["version"] != VERSION)
    {
        std::cerr << "Config.json has incorrect file version" << std::endl;
        return;
    }
    state = true;
    file.close();
}

void Converter_JSON::start() {
    if(state) return;
    LINE("Start");
    std::cout << "Name engine: " << json["name"] << std::endl;
    std::cout << "Version: " << json["version"] << std::endl;
}

void Converter_JSON::save_answere() {

    std::ofstream output("answers.json");
    if(!output.is_open())
    {
        std::cerr << "File output isnt open" << std::endl;
    }
    output << json;

    output.close();
}

int Converter_JSON::GetResponseLimit() {
    if(state) return 0;
    return json["config"]["max_response"];
}
