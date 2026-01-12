/**
 * @file    union_find.cpp
 * @brief	并查集
 * @author  gendloop
 */

// local
#include "union_find.h"

UnionFind::UnionFind()
{
    size_t size = parents_.size();
    for (auto i = 0; i < size; ++i) {
        parents_[i] = i; // 元素初始父结点为自己, 表示根结点
        ranks_[i] = 0;   // 初始秩为零
    }
}

int UnionFind::find(int x) const
{
    if (parents_[x] != x) {
        return find(parents_[x]);
    }
    return x;
}

void UnionFind::unite(int x, int y)
{
    // 求两集合的根结点
    int rootx = find(x);
    int rooty = find(y);
    if (rootx != rooty) {
        // 将秩小的集合合并到秩大的集合下
        if (ranks_[rootx] > ranks_[rooty]) {
            parents_[rooty] = rootx;
        }
        else if (ranks_[rootx] < ranks_[rooty]) {
            parents_[rootx] = rooty;
        }
        else {
            parents_[rooty] = rootx;
            ranks_[rootx]++;
        }
    }
}
