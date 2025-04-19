#pragma once
/**
 * @file	bipartite_graph_maximum_matching.h
 * @brief	相互喜欢的最大匹配问题
 * @author  gendloop
 */

// c++
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class BipartiteGraphMaximumMatching {
private:
    std::unordered_map<int, std::unordered_set<int>> graph_;
    std::unordered_map<int, int> match_;
    int count_;

public:
    BipartiteGraphMaximumMatching() = default;

    inline void setGraph(const std::unordered_map<int, std::unordered_set<int>>& graph) {
        graph_ = graph;
    }

    void search() {
        count_ = 0, match_.clear();

        for (auto& node : graph_) {
            for (int n : node.second)
                match_[n] = -1;
        }

        for (auto& node : graph_) {
            std::unordered_map<int, bool> visited;
            for (auto& node : graph_) {
                for (int n : node.second) {
                    visited[n] = false;
                }
            }
            if (DFS(node.first, graph_, match_, visited)) {
                count_++;
            }
        }
    }

    inline void printMatchedResult() const {
        for (auto node : match_) {
            if (node.second != -1) {
                std::cout << node.first << " => " << node.second << std::endl;
            }
        }
        std::cout << std::endl;
    }

    inline int getCount() const {
        return count_;
    }

protected:
    static bool DFS(int u, const std::unordered_map<int, std::unordered_set<int>>& graph,
        std::unordered_map<int, int>& match, std::unordered_map<int, bool>& visited)
    {
        for (auto p : graph.at(u)) {
            if (!visited[p]) {
                visited[p] = true;
                if (match[p] == -1 || DFS(match[p], graph, match, visited)) {
                    match[p] = u;
                    return true;
                }
            }
        }

        return false;
    }
};
