#ifndef SEARCH_ENGINE_SEARCH_SERVER_H
#define SEARCH_ENGINE_SEARCH_SERVER_H
#pragma once
#include <iostream>
#include <vector>
#include "../incl/Inverted_Index.h"


struct Relative_Index{
    size_t doc_id;
    float rank;

    bool operator == (const Relative_Index& other) const {
        return (doc_id == other.doc_id && rank == other.rank);
    }
};

class Search_Server
{
private:
    Inverted_Index _index;
    int response_limit = 4;
public:
    Search_Server(Inverted_Index& idx) : _index(idx){ };
    std::vector<std::vector<Relative_Index>> search(
            const std::vector<std::string>& queries_input);
    void set_response_limit(int val);

};
#endif //SEARCH_ENGINE_SEARCH_SERVER_H
