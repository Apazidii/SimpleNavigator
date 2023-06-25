#include <iostream>
#include <vector>
#include <stack>
#include <limits>
#include "s21_graph_algorithms.h"

const int INF = std::numeric_limits<int>::max(); // Бесконечность

struct State {
  int currCity;               // Текущий город
  std::vector<bool> visited;  // Посещенные города
  int currCost;               // Текущая стоимость пути
  std::vector<int> currPath;  // Текущий путь

  State(int city, const std::vector<bool>& v, int cost, const std::vector<int>& path)
    : currCity(city), visited(v), currCost(cost), currPath(path) {}
};

// Функция для вычисления нижней границы длины пути
int s21::GraphAlgorithms::calculateLowerBound(const std::vector<std::vector<int>>& graph, const std::vector<bool>& visited, int currCity) {
  int lowerBound = 0;

  // Находим два наименьших ребра в графе
  int minEdge1 = INF;
  int minEdge2 = INF;

  for (int i = 0; i < (int) graph.size(); ++i) {
    if (i != currCity && !visited[i]) {
      if (graph[currCity][i] < minEdge1) {
        minEdge2 = minEdge1;
        minEdge1 = graph[currCity][i];
      } else if (graph[currCity][i] < minEdge2) {
        minEdge2 = graph[currCity][i];
      }
    }
  }

  lowerBound += minEdge1 + minEdge2;

  for (int i = 0; i < (int) graph.size(); ++i) {
    if (i != currCity && !visited[i]) {
      int nextMinEdge1 = INF;
      int nextMinEdge2 = INF;

      for (int j = 0; j < (int) graph.size(); ++j) {
        if (j != currCity && j != i && !visited[j]) {
          if (graph[i][j] < nextMinEdge1) {
            nextMinEdge2 = nextMinEdge1;
            nextMinEdge1 = graph[i][j];
          } else if (graph[i][j] < nextMinEdge2) {
            nextMinEdge2 = graph[i][j];
          }
        }
      }

      lowerBound += nextMinEdge1 + nextMinEdge2;
    }
  }

  return lowerBound;
}

TsmResult s21::GraphAlgorithms::solveTSP(const std::vector<std::vector<int>>& graph) {
  int n = graph.size();

  std::vector<bool> visited(n, false);
  s21::Stack<State> stateStack;
  std::vector<int> bestPath;
  int minCost = INF;

  visited[0] = true; // Начинаем с первого города
  stateStack.push(State(0, visited, 0, std::vector<int>{0}));

  while (stateStack.size() != 0) {
    State currentState = stateStack.pop();

    int currCity = currentState.currCity;
    std::vector<bool> visited = currentState.visited;
    int currCost = currentState.currCost;
    std::vector<int> currPath = currentState.currPath;

    if ((int) currPath.size() == n) {
      // Если все города посещены
      currCost += graph[currCity][0]; // Возвращаемся в исходный город
      if (currCost < minCost) {
        minCost = currCost;
        bestPath = currPath;
      }
    } else {
      // Вычисляем нижнюю границу для текущего состояния
      int lowerBound = calculateLowerBound(graph, visited, currCity);
      if (lowerBound < minCost) {
        // Добавляем новые состояния в стек
        for (int i = 0; i < n; ++i) {
          if (!visited[i]) {
            visited[i] = true;
            currPath.push_back(i);
            stateStack.push(State(i, visited, currCost + graph[currCity][i], currPath));
            currPath.pop_back();
            visited[i] = false;
          }
        }
      }
    }
  }
    TsmResult res;
    bestPath.push_back(0);
    res.vertices = bestPath;
    res.distance = minCost;
  return res;
}

bool s21::GraphAlgorithms::checkFullGraph(std::vector<std::vector<int>> mat) {
    int s = (int) mat.size();

    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            if (i != j && mat[i][j] == 0)
                return false;
        }
    }
    return true;
}


TsmResult s21::GraphAlgorithms::solveTravelingSalesmanProblem3(s21::Graph &graph) {

    std::vector<std::vector<int>> mat;
    int **matrix = graph.getMatrix();
    int s = graph.getSize();

    for (int i = 0; i < s; i++) {
        std::vector<int> vec;
        for (int j = 0; j < s; j++) {
            vec.push_back(matrix[i][j]);
        }
        mat.push_back(vec);
    }

    if (!checkFullGraph(mat))
        return TsmResult();

    return solveTSP(mat);
}
