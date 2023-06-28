#include <gtest/gtest.h>
#include "s21_graph_algorithms.h"



// Фикстура для настройки и очистки перед выполнением тестов
class GraphAlgorithTest : public ::testing::Test {
protected:
    s21::Graph graph;

    void SetUp() override {
        std::ofstream out;
        out.open("test_graph.txt");
        if (out.is_open())
        {
            out << "0,1,0,1" << std::endl;
            out << "1,0,1,0" << std::endl;
            out << "0,1,0,0" << std::endl;
            out << "1,0,0,0";
        }
        out.close(); 
    }

    void TearDown() override {

        std::remove("test_graph.txt");
    }
};

TEST_F(GraphAlgorithTest, depthFirstSearch) {
    s21::Graph graph;
    graph.loadGraphFromFile("test_graph.txt");

    s21::GraphAlgorithms ga;

    std::vector<int> res = ga.depthFirstSearch(graph, 1);
    std::vector<int> expextedRes = {1, 2, 4, 3};

    for (size_t i = 0; i < res.size(); i++)
        EXPECT_EQ(res[i], expextedRes[i]);

}


TEST_F(GraphAlgorithTest, breadthFirstSearch) {


    s21::Graph graph;
    graph.loadGraphFromFile("test_graph.txt");
    s21::GraphAlgorithms ga;

    std::vector<int> res = ga.breadthFirstSearch(graph, 1);
    std::vector<int> expextedRes = {1, 4, 2, 3};

    for (size_t i = 0; i < res.size(); i++)
        EXPECT_EQ(res[i], expextedRes[i]);


}

TEST_F(GraphAlgorithTest, getShortestPathBetweenVertices) {


    s21::Graph graph;
    graph.loadGraphFromFile("test_graph.txt");
    s21::GraphAlgorithms ga;

    int res = ga.getShortestPathBetweenVertices(graph, 4, 3);
    int expextedRes = 3;

    EXPECT_EQ(res, expextedRes);
}

TEST_F(GraphAlgorithTest, getShortestPathsBetweenAllVertices) {
    s21::Graph graph;
    graph.loadGraphFromFile("test_graph.txt");
    s21::GraphAlgorithms ga;

    int s = graph.getSize();
    int **res = ga.getShortestPathsBetweenAllVertices(graph);
    std::vector<std::vector<int>> expextedRes = {
        {0, 1, 2, 1},
        {1, 0, 1, 2},
        {2, 1, 0, 3},
        {1, 2, 3, 0}
    };

    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            EXPECT_EQ(res[i][j], expextedRes[i][j]);
        }
    }

    for (int i = 0; i < s; ++i) {
        delete[] res[i];
    }
    delete[] res;
}

TEST_F(GraphAlgorithTest, getLeastSpanningTree) {
    s21::Graph graph;
    graph.loadGraphFromFile("test_graph.txt");
    s21::GraphAlgorithms ga;

    int s = graph.getSize();
    int **res = ga.getLeastSpanningTree(graph);
    std::vector<std::vector<int>> expextedRes = {
        {0, 1, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            EXPECT_EQ(res[i][j], expextedRes[i][j]);
        }
    }

    for (int i = 0; i < s; ++i) {
        delete[] res[i];
    }
    delete[] res;
}

// TEST_F(GraphAlgorithTest, solveTravelingSalesmanProblem) {
//     s21::Graph graph;
//     graph.loadGraphFromFile("test_graph.txt");
//     s21::GraphAlgorithms ga;

//     int s = graph.getSize();
//     int **res = ga.getLeastSpanningTree(graph);
//     std::vector<std::vector<int>> expextedRes = {
//         {0, 1, 0, 1},
//         {0, 0, 1, 0},
//         {0, 0, 0, 0},
//         {0, 0, 0, 0}
//     };

//     for (int i = 0; i < s; i++) {
//         for (int j = 0; j < s; j++) {
//             EXPECT_EQ(res[i][j], expextedRes[i][j]);
//         }
//     }

//     for (int i = 0; i < s; ++i) {
//         delete[] res[i];
//     }
//     delete[] res;
// }

// int main(int argc, char** argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }



