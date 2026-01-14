#include "pch.h"

#include <iostream>

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::FLAGS_gtest_filter += "Example.Case1";

    // Test specific
#if 1
    //::testing::FLAGS_gtest_filter += ":TestGraph.BipartiteGraphMaximumMatching";
    //::testing::FLAGS_gtest_filter += ":TestGraph.PointInPolygon";
    ::testing::FLAGS_gtest_filter += ":TestDataStructure.UnionFind";
#endif

    // Test all
#if 0
    ::testing::FLAGS_gtest_filter += ":TestGraph.*";
    ::testing::FLAGS_gtest_filter += ":TestDataStructure.*";
#endif

    return RUN_ALL_TESTS();
}
