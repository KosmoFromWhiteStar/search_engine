//
// Created by The_K on 17.08.2023.
//

#ifndef SEARCH_ENGINE_GTEST_SEARC_H
#define SEARCH_ENGINE_GTEST_SEARC_H
#include "../incl/Search_Server.h"
#include "gTest_Index.h"

TEST(TestCaseSearchServer, TestSimple) {
const vector<string> docs = {
        "milk milk milk milk water water water",
        "milk water water",
        "milk milk milk milk milk water water water water water",
        "americano cappuccino"
};
const vector<string> request = {"milk water", "sugar"};
const std::vector<vector<Relative_Index>> expected = {
        {
                {2, 1},
                {0, 0.7},
                {1, 0.3}
        },
        {        }
};
Inverted_Index idx;
idx.update_Document_Base(docs);
Search_Server srv(idx);
std::vector<vector<Relative_Index>> result = srv.search(request);
ASSERT_EQ(result, expected);
}
TEST(TestCaseSearchServer, TestTop5) {
const vector<string> docs = {
        "london is the capital of great britain",
        "paris is the capital of france",
        "berlin is the capital of germany",
        "rome is the capital of italy",
        "madrid is the capital of spain",
        "lisboa is the capital of portugal",
        "bern is the capital of switzerland",
        "moscow is the capital of russia",
        "kiev is the capital of ukraine",
        "minsk is the capital of belarus",
        "astana is the capital of kazakhstan",
        "beijing is the capital of china",
        "tokyo is the capital of japan",
        "bangkok is the capital of thailand",
        "welcome to moscow the capital of russia the third rome",
        "amsterdam is the capital of netherlands",
        "helsinki is the capital of finland",
        "oslo is the capital of norway",
        "stockholm is the capital of sweden",
        "riga is the capital of latvia",
        "tallinn is the capital of estonia",
        "warsaw is the capital of poland",
};

const vector<string> request = {"moscow is the capital of russia"};
const std::vector<vector<Relative_Index>> expected = {
        {
                {7, 1},
                {14, 1},
                {0, 0.666666687},
                {1, 0.666666687},
                {2, 0.666666687}
        }
};
Inverted_Index idx;
idx.update_Document_Base(docs);
Search_Server srv(idx);
std::vector<vector<Relative_Index>> result = srv.search(request);
ASSERT_EQ(result, expected);
}
#endif //SEARCH_ENGINE_GTEST_SEARC_H
