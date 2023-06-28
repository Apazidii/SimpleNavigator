#include "s21_graph_algorithms.h"

bool s21::GraphAlgorithms::edgeInVec(std::vector<int> vec, int a, int b) {
    int s = vec.size();
    for (int i = 1; i < s; i++) {
        if (vec[i - 1] == a && vec[i] == b)
            return true;
    }
    return false;
}

bool s21::GraphAlgorithms::checkConnectedGraph(s21::Graph &graph) {
    int s = graph.getSize();
    for (int i = 0; i < s; i++) {
        std::vector<int> res = depthFirstSearch(graph, i + 1);
        if ((int) res.size() != s)
            return false;
    }
    return true;
}


int s21::GraphAlgorithms::getRandomIndex(const std::vector<double>& probabilities) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::discrete_distribution<> dist(probabilities.begin(), probabilities.end());
    return dist(gen);
}

void s21::GraphAlgorithms::updatePhero(double **phero, Ant &ant, int s) {
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            double antPhero = 0.0;
            if (edgeInVec(ant.vertices, i, j))
                antPhero = 1.0 / ant.distance;
            phero[i][j] = (1.0 - RHO) * phero[i][j] + antPhero;
        }
    }
}


double s21::GraphAlgorithms::probabilityEdge(double edge, double phero) {
    double pheroProb = std::pow(std::abs(phero) , ALPHA);
    double attractProb = std::pow(std::abs(1.0 / edge), BETA);
    return pheroProb * attractProb;
}


void s21::GraphAlgorithms::startAntJourney(Ant &ant, Graph &graph, double**phero, bool *visits) {
    int node = ant.vertices.back();
    int s = graph.getSize();
    visits[node] = true;
    
    std::vector<double> probability(s, 0.0);



    int *nextNodes = graph.getNodes(node);

    double sumProb = 0.0;
    for (int i = 0; i < s; i++) {
        if (nextNodes[i] != 0)
            sumProb += probabilityEdge(nextNodes[i], phero[node][i]); 
    }
    
    for (int i = 0; i < s; i++) {
        if (nextNodes[i] != 0 && (!visits[i] || ant.vertices.size() >= (size_t) s))
            probability[i] = probabilityEdge(nextNodes[i], phero[node][i]) / sumProb;
    }
    int nextMove = getRandomIndex(probability);
    ant.distance += nextNodes[nextMove];
    ant.vertices.push_back(nextMove);
}


TsmResult s21::GraphAlgorithms::solveTravelingSalesmanProblem(Graph &graph) {
    Ant ant;
    ant.distance = 0;
    if (!checkConnectedGraph(graph))
        return ant;
    int s = graph.getSize();
    double **pheroMap = new double*[s];
    for (int i = 0; i < s; ++i) {
        pheroMap[i] = new double[s];
        for (int j = 0; j < s; j++)
            pheroMap[i][j] = basePheromone;
    }

    bool *visits = new bool[s];
    for (int i = 0; i < s; i++)
        visits[i] = false;





    
    int start;
    for (int i = 0; i < antCount; i++) {
        start = rand() % s;
        ant.vertices.clear();
        ant.distance = 0.0;
        ant.vertices.push_back(start);
        for (int i = 0; i < s; i++)
            visits[i] = false;
        while (ant.vertices.size() < (size_t) s || ant.vertices.back() != start) {
            startAntJourney(ant, graph, pheroMap, visits);
        }
        updatePhero(pheroMap, ant, s);


    }







    for (int i = 0; i < s; ++i) {
        delete[] pheroMap[i];
    }
    delete[] pheroMap;
    delete[] visits;
    for (size_t i = 0; i < ant.vertices.size(); i++)
        ant.vertices[i] += 1;
    return ant;
}
