#include "s21_graph_algorithms.h"

int **s21::GraphAlgorithms::getLeastSpanningTree(Graph &graph) {
    int s = graph.getSize();

    bool *visits = new bool[s];
    for (int i = 0; i < s; i++)
        visits[i] = false;
    
    int **resMat = new int*[s];
    for (int i = 0; i < s; ++i) {
        resMat[i] = new int[s];
        for (int j = 0; j < s; j++)
            resMat[i][j] = 0;
    }

    
    std::vector<int> way;
    way.push_back(0);
    visits[0] = true;
    
    int minIndS, minIndF, min = INT32_MAX;

    int ws = way.size();
    while(ws != s) {
        ws = way.size();


        //TODO упаковать в отдельную функцию
        for (int nodeInd = 0; nodeInd < ws; nodeInd++) {
            int node = way[nodeInd];
            int *nextNodes = graph.getNodes(node);
            for (int nextNodeInd = 0; nextNodeInd < s; nextNodeInd++) {
                if (!(nextNodes[nextNodeInd] == 0 || visits[nextNodeInd])) {
                    if (min > nextNodes[nextNodeInd]) {
                        min = nextNodes[nextNodeInd];
                        minIndS = node;
                        minIndF = nextNodeInd;
                    }
                }
            }
        }

        if (min != INT32_MAX) { 
            way.push_back(minIndF);
            visits[minIndF] = true;
            resMat[minIndS][minIndF] = min;
            min = INT32_MAX;
        } else if (ws != s) {
            printf("Граф не связный\n");
            delete []visits;
            for (int i = 0; i < s; ++i) {
                delete[] resMat[i];
            }
            delete[] resMat;
            return nullptr;
        }
    }
    delete []visits;

    return resMat;
}



