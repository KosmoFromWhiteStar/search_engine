//
// Created by The_K on 16.08.2023.
//

#include "../incl/Converter_JSON.h"

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
    //
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
    if(!state) return;
    LINE("Start");
    std::cout << "Name engine: " << json["config"]["name"] << std::endl;
    std::cout << "Version: " << json["config"]["version"] << std::endl;
}

int Converter_JSON::get_Response_Limit() {
    if(!state) return 0;
    return json["config"]["max_responses"];
}

void Converter_JSON::put_Answere(std::vector<std::pair<int, float>> answere) {

}
