#include "pch.h"

// local
#include "../src/data-structure/union_find.h"

TEST(TestDataStructure, UnionFind) {
    UnionFind uf(10);
    // 构建集合
    uf.unite(1, 2);
    uf.unite(1, 3);
    uf.unite(1, 4);
    uf.unite(5, 6);
    uf.unite(6, 7);
    uf.unite(8, 9);
    // 测试连通性
    EXPECT_TRUE(uf.connected(2, 4));
    EXPECT_FALSE(uf.connected(2, 7));
    EXPECT_FALSE(uf.connected(6, 9));
    // 测试合并
    uf.unite(4, 5);
    EXPECT_TRUE(uf.connected(2, 7));
    EXPECT_FALSE(uf.connected(6, 9));
    uf.unite(6, 9);
    EXPECT_TRUE(uf.connected(2, 7));
    EXPECT_TRUE(uf.connected(6, 9));
}
