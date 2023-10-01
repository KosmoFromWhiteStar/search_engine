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
#include "nlohmann/json.hpp"

//Дефайны для удобства
#define VERSION "1"
#define REQUEST(x) ("request" + (x))

#define LINE(s) std::cout << "========[ " << (s) << " ]========" << std::endl

using js = nlohmann::json;

/**
* Класс для работы с JSON-файлами
*/
class Converter_JSON
{
private:
    js file_j;
    //состояние класса.
    bool state = false;
    //Путь к папке с конфигурацией
    std::string path = "../Conf/";
public:
    //Конструктор
    Converter_JSON();
    Converter_JSON(std::string in_path);;

    //First method to start this class
    void start();

    /*
    * Метод получения содержимого файлов
    * @return Возвращает список с содержимым файлов перечисленных в config.json
    */
    std::vector<std::string> get_Text_Document();

    /**
    * Метод считывает поле max_responses для каждого предельного
    * количества ответов на один запрос
    * @return
    **/
    int get_Response_Limit();

    /**
    * Метод получения запросов из файла requests.json
    * @return возвращает список запросов из файла requests.json
    **/
    std::vector<std::string> get_Request();\

    /**
     * Положить в файл answers.json результаты поисковых запросов
     * Put answers in JSON file
     * Take result
     * first vec - request
     * second vec - Pair doc_id and rank search in this file
     * @param result of search (dont converted result Search_Server::search())
     **/
    void put_Answere(std::vector<std::vector<std::pair<size_t, float>>> answere);
    js get_js(){return file_j;}
    bool get_state(){return state;}
};


#endif //SEARCH_ENGINE_CONVERTER_JSON_H
