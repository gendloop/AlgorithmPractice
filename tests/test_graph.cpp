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
    using Point = PointInPolygon::Point;
    PointInPolygon t;
    std::vector<Point> polygon;
    Point p;
    
    // 矩形
    {
        polygon = {
            {-3, -3}, {-3,  3},
            { 3,  3}, { 3, -3}
        };

        p = { 0, 0 };
        std::cout << (t.isPointInPolygon(polygon, p) ? "in" : "out") << std::endl;
    }

    // 凹多边形
    {
        polygon = {
            {0, 0}, {4, 0}, {4, 4}, {2, 2}, {0, 4}
        };

        p = { 1, 1 };
        std::cout << (t.isPointInPolygon(polygon, p) ? "in" : "out") << std::endl;
        p = { 2, 4 };
        std::cout << (t.isPointInPolygon(polygon, p) ? "in" : "out") << std::endl;
    }
}
