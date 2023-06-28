#include <gtest/gtest.h>
#include "s21_graph.h"

TEST(GraphTest, LoadGraphFromFile) {
    std::ofstream out;          // поток для записи
    out.open("test_graph.txt");      // открываем файл для записи
    if (out.is_open())
    {
        out << "0,1,0,1" << std::endl;
        out << "1,0,1,0" << std::endl;
        out << "0,1,0,0" << std::endl;
        out << "1,0,0,0";
    }
    out.close(); 

    s21::Graph graph;
    graph.loadGraphFromFile("test_graph.txt");

    // Проверяем, что матрица была инициализирована
    EXPECT_TRUE(graph.getMatrix() != nullptr);

    // Проверяем размер матрицы
    EXPECT_EQ(graph.getSize(), 4);

    // Проверяем значения матрицы
    int expectedMatrix[4][4] = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 0},
        {1, 0, 0, 0}
    };

    int** matrix = graph.getMatrix();
    for (int i = 0; i < graph.getSize(); ++i) {
        for (int j = 0; j < graph.getSize(); ++j) {
            EXPECT_EQ(matrix[i][j], expectedMatrix[i][j]);
        }
    }
    std::remove("test_graph.txt");
}

TEST(GraphTest, ExportGraphToDot) {
    std::ofstream out;          // поток для записи
    out.open("test_graph.txt");      // открываем файл для записи
    if (out.is_open())
    {
        out << "0,1,0,1" << std::endl;
        out << "1,0,1,0" << std::endl;
        out << "0,1,0,0" << std::endl;
        out << "1,0,0,0";
    }
    out.close();
    s21::Graph graph;
    graph.loadGraphFromFile("test_graph.txt");
    graph.exportGraphToDot("test_output.dot");

    // Проверяем, что файл был успешно создан
    std::ifstream outputFile("test_output.dot");
    EXPECT_TRUE(outputFile.good());

    // Проверяем содержимое файла
    std::string line;
    std::string expectedContent = "graph graphname {\n"
                                  "\ta;\n"
                                  "\tb;\n"
                                  "\tc;\n"
                                  "\td;\n"
                                  "\ta -- b;\n"
                                  "\ta -- d;\n"
                                  "\tb -- c;\n"
                                  "}\n";
    std::string actualContent;

    while (std::getline(outputFile, line)) {
        actualContent += line + "\n";
    }

    EXPECT_EQ(actualContent, expectedContent);

    outputFile.close();
    std::remove("test_graph.txt");

}

