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
    file >> file_j;
    //
    if(file_j["config"] == nullptr)
    {
        std::cerr << "Config is empty" << std::endl;
        return;
    }
    if(file_j["config"]["version"] != VERSION)
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
    std::cout << "Name engine: " << file_j["config"]["name"] << std::endl;
    std::cout << "Version: " << file_j["config"]["version"] << std::endl;
}

std::vector<std::string> Converter_JSON::get_Text_Document()
{
    std::vector<std::string> result;
    for(int i = 0; i < file_j["files"].size(); i++)
    {
        std::string path = file_j["files"][i];
        std::ifstream file (path);
        std::string sentence = "";
        if(file.is_open())
        {
            while (!file.eof())
            {
                std::string word;
                file >> word;
                sentence += word + ' '; 
            }   
        }
        else
        {
            std::cerr << file_j["files"][i] << " isn't work" << std::endl;
        }
        result.push_back(sentence);
    }
    return result;
}

std::vector<std::string> Converter_JSON::get_Request()
{
    std::ifstream file("..//..//requests.json");
    if(!file.is_open())
    {
        std::cerr << "requsets.jsom file isn't open" << std::endl;
    }
    js requests;
    file >> requests;
    file.close();

    std::vector<std::string> words;
    for(int i = 0; i < requests["requests"].size(); i++)
    {
        words.push_back(requests["requests"][i]);
    }
    return words;
}

int Converter_JSON::get_Response_Limit() 
{
    if(!state) return 0;
    return file_j["config"]["max_responses"];
}

void Converter_JSON::put_Answere(std::vector<std::vector<std::pair<size_t, float>>> answere)
{
    LINE("Put answere");
    std::ofstream file("..//..//answere.json");
    if(!file.is_open())
    {
        std::cout << "Answere file isn't open" << std::endl;
    }

    file << "{\n\"answers\": {\n";
    for(int i = 0; i < answere.size(); i++)
    {
        file << REQUEST(i);
        if(answere[i].empty())
        {
            file << FALSE;
            if(!(i + 1 == answere.size()))
            {
                file << ',';
            }
            continue;
        }
        file << TRUE;
        for(int j = 0; j < answere[i].size(); j++)
        {
            file << REL;
            file << DOC_ID << answere[i][j].first
            << RANK << answere[i][j].second;
            if(!(j + 1 == answere[i].size()))
            {
                file << ",";
            }
            file << '\n';
        }
        file << "}";
        if(!(i + 1 == answere.size()))
        {
            file << ',';
        }
        file << '\n';
    }
    file << "}\n";
    file << "}";
    file.close();
}


