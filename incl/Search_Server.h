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

    /*
     * @param idx в конструктор класса передаётся ссылка на класс InvertedIndex,
     * чтобы SearchServer мог узнать частоту слов встречаемых в запросе
    */
    Search_Server(Inverted_Index& idx) : _index(idx){ };

    /*
     * Метод обработки поисковых запросов
     * @param queries_input поисковые запросы взятые из файла requests.json
     * @return возвращает отсортированный список релевантных ответов для заданных запросов
    */
    std::vector<std::vector<Relative_Index>> search(
            const std::vector<std::string>& queries_input);

    //Устанавливает лимит ответа
    void set_response_limit(int val);

};
#endif //SEARCH_ENGINE_SEARCH_SERVER_H
