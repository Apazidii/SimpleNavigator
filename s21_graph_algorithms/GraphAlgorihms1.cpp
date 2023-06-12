#include "s21_graph_algorithms.h"


std::vector<int> s21::GraphAlgorithms::FirstSearch(Graph &graph, s21::BaseContainer<int> *cont) {
    int s = graph.getSize();
    bool *visits = new bool[s];
    for (int i = 0; i < s; i++)
        visits[i] = false;

    std::vector<int> way;

    while (cont->size() != 0)
    {
        int node = cont->pop();

        way.push_back(node + 1);
        visits[node] = true;
        int *nextNodes = graph.getNodes(node);

        for (int i = 0; i < s; i++) {
            if (nextNodes[i] != 0 && !visits[i]) {
                cont->push(i);
                visits[i] = true;
            }
        }
    }
    delete[] visits;
    return way;

}


std::vector<int> s21::GraphAlgorithms::breadthFirstSearch(Graph &graph, int startVertex) {
    std::vector<int> way;
    startVertex--;
    if (startVertex > graph.getSize() || startVertex < 0) {
        return way;
    }

    s21::Stack<int> cont;
    cont.push(startVertex);
    way = FirstSearch(graph, &cont);
    return way;
}


std::vector<int> s21::GraphAlgorithms::depthFirstSearch(Graph &graph, int startVertex) {
    std::vector<int> way;
    startVertex--;
    if (startVertex > graph.getSize() || startVertex < 0) {
        return way;
    }

    s21::Queue<int> cont;
    cont.push(startVertex);
    way = FirstSearch(graph, &cont);
    return way;
}