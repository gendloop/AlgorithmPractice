#include "pch.h"

// local
#include "../src/graph/bipartite_graph_case1.h"

TEST(TestBipartiteGraphCase1, T1) {
    std::unordered_map<int, std::unordered_set<int>> graph{
        {1, {6}},
        {2, {5, 8}},
        {3, {6}},
        {4, {6, 7}},
    };

    BipartiteGraphCase1 bg;
    bg.setGraph(graph);
    bg.search();
    bg.printMatchedResult();
    std::cout << bg.getCount() << std::endl;
}

