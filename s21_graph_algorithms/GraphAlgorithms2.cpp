#include "s21_graph_algorithms.h"


bool s21::GraphAlgorithms::isINF(int **mat, int i, int j) {
    return (mat[i][j] == 0 && i != j);
}

int s21::GraphAlgorithms::getShortestPathBetweenVertices(Graph &graph, int vertex1, int vertex2) {
    vertex1--;
    vertex2--;
    int s = graph.getSize();
    if (vertex1 > s || vertex2 > s || vertex1 < 0 || vertex2 < 0)
        return -1;
    bool *visits = new bool[s];
    for (int i = 0; i < s; i++)
        visits[i] = false;
    Queue<int> cont;
    cont.push(vertex1);

    int *longWays = new int[s];
    for (int i = 0; i < s; i++)
        longWays[i] = -2;

    while (cont.size() != 0)
    {
        int node = cont.pop();

        visits[node] = true;
        int *nextNodes = graph.getNodes(node);
        
        for (int i = 0; i < s; i++) {
            if (nextNodes[i] != 0 && !visits[i]) {
                if (longWays[i] == -2 || longWays[i] > longWays[node] + nextNodes[i])
                    longWays[i] = longWays[node] + nextNodes[i];
                cont.push(i);
            }
        }
    }
    delete[] visits;
    int res = longWays[vertex2];
    delete[] longWays;
    return res;


}


int **s21::GraphAlgorithms::getShortestPathsBetweenAllVertices(Graph &graph) {
    int s = graph.getSize();
    int **mat = graph.getMatrix();
    int **matrix = new int*[s];
    for (int i = 0; i < s; ++i) {
        matrix[i] = new int[s];
        for (int j = 0; j < s; j++)
        {
                matrix[i][j] = mat[i][j];
        }
    }


    for(int k = 0; k < s; k++) {
        for(int i = 0; i < s; i++) {
            for(int j = 0; j < s; j++) {

                if (isINF(matrix, i, k) || isINF(matrix, k, j))
                    matrix[i][j] = matrix[i][j];
                else if (isINF(matrix, i, j))
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                else
                    matrix[i][j] = std::min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }  
        }
    }
    return matrix;
}