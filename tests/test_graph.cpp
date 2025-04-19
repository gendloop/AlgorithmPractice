#include "pch.h"

// local
#include "../src/graph/bipartite_graph_maximum_matching.h"
#include "../src/graph/point_in_polygon.h"

TEST(TestGraph, BipartiteGraphMaximumMatching) {
    std::unordered_map<int, std::unordered_set<int>> graph{
        {1, {6}},
        {2, {5, 8}},
        {3, {6}},
        {4, {6, 7}},
    };

    BipartiteGraphMaximumMatching bg;
    bg.setGraph(graph);
    bg.search();
    bg.printMatchedResult();
    std::cout << bg.getCount() << std::endl;
}

TEST(TestGraph, PointInPolygon) {
    // todo
}
