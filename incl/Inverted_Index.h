//
// Created by The_K on 17.08.2023.
//

#ifndef SEARCH_ENGINE_INVERTED_INDEX_H
#define SEARCH_ENGINE_INVERTED_INDEX_H
#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <thread>
#include <atomic>
#include "nlohmann/json.hpp"


struct Entry
{
    size_t doc_id, count;
    // for Tests
    bool operator == (const Entry& other) const {
        return (doc_id == other.doc_id &&
                count == other.count);
    }
};

class Inverted_Index
{
private:
    //Состояние работы класса
    bool state = true;
    std::vector<std::string> docs; // список содержимого документов
    std::map<std::string, std::vector<Entry>> freq_dictionary; // частотный словарь

public:
    //Конструктор
    Inverted_Index() = default;

    /**
    * Обновить или заполнить базу документов, по которой будем совершать поиск
    * @param texts содержимое документов
    **/
    void update_Document_Base(std::vector<std::string> text);

    /**
    * Метод определяет количество вхождений слова word в загруженной базе документов
    * @param word слово, частоту вхождений которого необходимо определить
    * @return возвращает подготовленный список с частотой слов
    */
    std::vector<Entry> get_Word_Count(const std::string& word);
};

#endif //SEARCH_ENGINE_INVERTED_INDEX_H
