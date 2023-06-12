#include "s21_graph.h"


// Возвращает матрицу
int ** s21::Graph::getMatrix() {return matrix;}

// Возвращает размер матрицы
int s21::Graph::getSize() {return size;}


int *s21::Graph::getNodes(int node) {
    return matrix[node];
}