#ifndef S21_GRAPH_ALGORITHMS_H
# define S21_GRAPH_ALGORITHMS_H

#include "s21_graph.h"
#include "containers.h"
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <random>


struct TsmResult {
    std::vector<int> vertices;    // массив с искомым маршрутом (с порядком обхода вершин). Вместо int* можно использовать std::vector<int>
    double distance;  // длина этого маршрута
};

using Ant = TsmResult;

namespace s21 {
    class GraphAlgorithms {
        private:
            std::vector<int> FirstSearch(Graph &graph, s21::BaseContainer<int> *cont);
            bool isINF(int **mat, int i, int j);

        private:
            void startAntJourney(Ant &ant, Graph &graph, double**phero, bool *visits);
            double probabilityEdge(double attract, double phero);
            int getRandomIndex(const std::vector<double>& probabilities);
            void updatePhero(double **phero, Ant &ant, int s);
            bool edgeInVec(std::vector<int> vec, int a, int b);

        public:
            //part1
            std::vector<int> depthFirstSearch(Graph &graph, int startVertex);
            std::vector<int> breadthFirstSearch(Graph &graph, int startVertex);
            //part2
            int     getShortestPathBetweenVertices(Graph &graph, int vertex1, int vertex2);
            int**   getShortestPathsBetweenAllVertices(Graph &graph);
            //part3
            int **getLeastSpanningTree(Graph &graph);
            //part4
            TsmResult solveTravelingSalesmanProblem(Graph &graph);

        //part4 options
        private:
            double basePheromone = 1.0; // Базовое значение феромонов
            int antCount = 100;          // Количество муравьев
            double ALPHA = 1.0;         // Влияние феромонов
            double BETA = 2.0;          // Влияние эвристической информации
            double RHO = 0.5;           // Скорость испарения феромонов
    };
}


#endif