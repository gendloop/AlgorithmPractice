/**
 * @file    union_find.cpp
 * @brief	并查集
 * @author  gendloop
 */

// local
#include "union_find.h"

UnionFind::UnionFind(int n)
{
    parents_.resize(n);
    ranks_.resize(n, 0); // 初始秩为零
    for (auto i = 0; i < n; ++i) {
        parents_[i] = i; // 元素初始父结点为自己, 表示根结点
    }
}

int UnionFind::find(int x)
{
    if (parents_[x] != x) {
        parents_[x] = find(parents_[x]); // 路径压缩
    }
    return parents_[x];
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

bool UnionFind::connected(int x, int y)
{
    return find(x) == find(y);
}
