#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include "s21_graph_algorithms.h"

const int INF = std::numeric_limits<int>::max();

void s21::GraphAlgorithms::recursiveTSM2(const std::vector<std::vector<int>>& graph, std::vector<int>& path, std::vector<bool>& visited, int current, int n, int cost, int& minCost, std::vector<int>& minPath) {
  if (n == graph.size() && graph[current][0] != INF) {
    // Все вершины посещены, обновляем минимальный путь и стоимость
    cost += graph[current][0];
    if (cost < minCost) {
      minCost = cost;
      minPath = path;
    }
    return;
  }

  for (int i = 0; i < graph.size(); ++i) {
    if (!visited[i] && graph[current][i] != INF) {
      visited[i] = true;
      path[n] = i;

      recursiveTSM2(graph, path, visited, i, n + 1, cost + graph[current][i], minCost, minPath);

      visited[i] = false;
    }
  }
}

TsmResult s21::GraphAlgorithms::solveTravelingSalesmanProblem2(s21::Graph &g) {
    int n;
    g.loadGraphFromFile("./file_examples/1");
    n = g.getSize();
    int **mat = g.getMatrix();

    std::vector<std::vector<int>> graph(n, std::vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            graph[i][j] = mat[i][j];
            if (mat[i][j] == 0)
                graph[i][j] = INF;
        }
            

    std::vector<int> path(n);
    std::vector<bool> visited(n, false);

    visited[0] = true; // Начинаем с вершины 0
    path[0] = 0;

    int minCost = INF;
    std::vector<int> minPath;

    recursiveTSM2(graph, path, visited, 0, 1, 0, minCost, minPath);

    for (int i = 0; i < n; ++i) {
        minPath[i] +=1;
    }
    minPath.push_back(1);


    TsmResult res;
    res.vertices = minPath;
    res.distance = minCost;
    return res;
}

