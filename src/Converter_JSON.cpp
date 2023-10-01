//
// Created by The_K on 16.08.2023.
//

#include "../incl/Converter_JSON.h"


Converter_JSON::Converter_JSON()
{
    std::ifstream file;
    file.open(path + "config.json");
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

Converter_JSON::Converter_JSON(std::string in_path) : path(in_path)
{
    std::ifstream file;
    file.open(path + "config.json");
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
    if(!state)
    {
        std::cout << "Err" << std::endl;
        return std::vector<std::string> {};
    }
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
    if(!state) {
        std::cout << "Err" << std::endl;
        return std::vector<std::string>{};
    }
    std::ifstream file(path + "requests.json");
    if(!file.is_open())
    {
        std::cerr << "requsets.jsom file isn't open" << std::endl;
        state = false;
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
    if(!state) {
        std::cout << "Err" << std::endl;
        return;
    }
    LINE("Put answere");

    js js_file;
    //file << "{\n\"answers\": {\n";
    js_file["answere"];
    for(int i = 0; i < answere.size(); i++)
    {
        //
        std::string number = "";
        if(i < 10)
        {
            number = "00" + std::to_string(i + 1);
        }
        else if(i < 100)
        {
            number = "0" + std::to_string(i + 1);
        }
        else number = std::to_string(i + 1);
        js_file["answere"][REQUEST(number)];
        //
        if(answere[i].empty())
        {
            js_file["answere"][REQUEST(number)]["result"] = false;
        }
        else
        {
            js ne_js;
            for(int j = 0; j < answere[i].size(); j++)
            {
                ne_js[j]["doc_id"] = answere[i][j].first;
                ne_js[j]["rank"] = answere[i][j].second;
            }
            js_file["answere"][REQUEST(number)]["result"] = true;
            if(answere[i].size() > 1)
            {
                js_file["answere"][REQUEST(number)]["relevance"] = ne_js;
            }
            else js_file["answere"][REQUEST(number)] = ne_js;
        }
    }
    std::ofstream file(path + "answere.json");
    if(!file.is_open())
    {
        std::cout << "Answere file isn't open" << std::endl;
        return;
    }
    file << js_file;
    file.close();
}




