#pragma once
/**
 * @file    union_find.h	
 * @brief	并查集
 * @author  gendloop
 */

// c++
#include <vector>

class UnionFind {
private:
    std::vector<int> parents_; ///< 每个元素的父结点
    std::vector<int> ranks_;   ///< 元素所在集合的秩

public:
    UnionFind();

    /// 查找根结点
    int find(int x) const;

    /// 合并两个元素所在的集合
    void unite(int x, int y); 
};
