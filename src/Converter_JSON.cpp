//
// Created by The_K on 16.08.2023.
//

#include "../incl/Converter_JSON.h"


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

std::vector<std::string> Converter_JSON::get_Text_Document()
{
    std::vector<std::string> result;
    for(int i = 0; i < json["files"].size(); i++)
    {
        std::ifstream file (json["files"][i]);
        std::string sentence = "";
        if(file.is_open())
        {
            std::string word;
            file >> word;
            sentence+= word;
        }
        else
        {
            std::cerr << json["files"][i] << " isn't work" << std::endl;
        }
        result.push_back(sentence);
    }
}

int Converter_JSON::get_Response_Limit() {
    if(!state) return 0;
    return json["config"]["max_responses"];
}

void Converter_JSON::put_Answere(std::vector< std::vector< std::pair<int, float> > > answere)
{
    std::ofstream file("..//..//answere.json");
    if(!file.is_open())
    {
        std::cout << "Answere file isn't open" << std::endl;
    }

    file << "{\n\"answers\": {\n";
    for(int i = 0; i < answere.size(); i++)
    {
        file << ("\"request"+std::to_string(i)) << "\": {";
        file << "\"result\": ";
        if(!answere[i].empty())
        {
            file << TRUE;
            for(int j = 0; i < answere[i].size(); j++)
            {
                file << DOC_ID << answere[i][j].first
                << RANK << answere[i][j].second;
            }
        }
        else { file << FALSE; }
    }
    file << "}";
    file.close();
}


