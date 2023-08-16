//
// Created by The_K on 17.08.2023.
//

#ifndef SEARCH_ENGINE_INVERTED_INDEX_H
#define SEARCH_ENGINE_INVERTED_INDEX_H
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <filesystem>
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
    std::vector<std::string> docs;
    std::map<std::string, std::vector<Entry>> freq_dictionary;
public:
    Inverted_Index();


}

#endif //SEARCH_ENGINE_INVERTED_INDEX_H
