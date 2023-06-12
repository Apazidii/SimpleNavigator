#include "s21_graph.h"
// Деструктор, отчищает матрицу
s21::Graph::~Graph() {
    freeMatrix();
}
// Функция отчистки памяти матрицы
void s21::Graph::freeMatrix() {
    if (matrix == nullptr)
        return;
    for (int i = 0; i < size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// Переводит номер узла в имя 
std::string s21::Graph::numberToString(int num) {
    std::string result;
    
    while (num >= 0) {
        result = static_cast<char>('a' + num % 26) + result;
        num = (num / 26) - 1;
        
        if (num < 0) {
            break;
        }
    }
    
    return result;
}

// Возвращает true если граф неориентирован
// и false если граф ориентирован
bool s21::Graph::typeGraph() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (matrix[i][j] != matrix[j][i])
                return false;
        }
    }
    return true;
}