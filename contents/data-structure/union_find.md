# 并查集

## 含义

并查集是一种管理元素所属集合的数据结构, 可以看作一个森林, 一棵树表示一个集合. 常用于判定图的连通性.

并查集支持两种操作:
* 合并(Unite): 合并两个元素所属的集合;
* 查询(Find): 查询某个元素所在树的根结点.

路径压缩: *查询过程*中经过的每个元素都属于该集合, 故可将其看作直接连到根结点的树.

## 实现

[import](../../src/data-structure/union_find.h)
[import](../../src/data-structure/union_find.cpp)

## 拓展

* 带删除并查集
* 带权并查集

## References

1. [并查集](https://oi-wiki.org/ds/dsu/)
