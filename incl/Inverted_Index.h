//
// Created by The_K on 17.08.2023.
//
#pragma once
#ifndef SEARCH_ENGINE_INVERTED_INDEX_H
#define SEARCH_ENGINE_INVERTED_INDEX_H
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <filesystem>
#include <thread>
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
    bool state = false;
    std::vector<std::string> docs;
    std::map<std::string, std::vector<Entry>> freq_dictionary;
    class Converter_JSON* json;
public:
    Inverted_Index(Converter_JSON* in_json);
    void update_Document_Base(std::vector<std::string> text);
    std::vector<Entry> get_Word_Count(const std::string& word);
};


#endif //SEARCH_ENGINE_INVERTED_INDEX_H
