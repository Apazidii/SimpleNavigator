#include "s21_graph.h"




void s21::Graph::loadGraphFromFile(std::string filename) {
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cout << "Не удалось открыть файл." << std::endl;
        matrix = nullptr;
        return ;
    }
    
    // Определение размера матрицы
    std::string line;
    size = 0;
    while (std::getline(file, line)) {
        ++size;
    }
    
    // Выделение памяти под матрицу
    matrix = new int*[size];
    for (int i = 0; i < size; ++i) {
        matrix[i] = new int[size];
    }
    
    // Сброс указателя чтения файла в начало
    file.clear();
    file.seekg(0, std::ios::beg);
    
    // Чтение данных из файла в матрицу
    int row = 0;
    while (std::getline(file, line)) {
        size_t pos = 0;
        int col = 0;
        while ((pos = line.find(',')) != std::string::npos) {
            std::string value = line.substr(0, pos);
            matrix[row][col] = std::stoi(value);
            line.erase(0, pos + 1);
            ++col;
        }
        matrix[row][col] = std::stoi(line);
        ++row;
    }
    init = true;
    file.close();
}


void s21::Graph::exportGraphToDot(std::string filename) {

    FILE* file = fopen(filename.c_str(), "w");
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return ;
    }
    

    if (typeGraph())
        fprintf(file, "graph %s {\n", name.c_str());
    else
        fprintf(file, "digraph %s {\n", name.c_str());

    for (int i = 0; i < size; i++) {
        fprintf(file, "\t%s;\n", numberToString(i).c_str());
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j || matrix[i][j] == 0)
                continue;
            if (matrix[i][j] == matrix[j][i] && i > j)
                continue;
            if (matrix[i][j] == matrix[j][i])
                fprintf(file, "\t%s %s %s;\n", numberToString(i).c_str(), "--", numberToString(j).c_str());
            else
                fprintf(file, "\t%s %s %s;\n", numberToString(i).c_str(), "->", numberToString(j).c_str());
        }   
    }
    fprintf(file, "}");
    

    fclose(file);

}