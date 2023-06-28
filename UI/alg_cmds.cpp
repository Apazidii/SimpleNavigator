#include "UI.h"


void s21::ConsoleUI::DFS(s21::Graph &graph) {
    if (!graph.init) {
        std::cout << RED << "Требуется загрузить граф" << RESET << std::endl;
        return ;
    }
    s21::GraphAlgorithms ga;
    std::cout << MAGENTA << "Введите стартувую вершину" << RESET << std::endl;
    int start;
    std::cin >> start;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::vector<int> way = ga.depthFirstSearch(graph, start);
    if (way.size() == 0) {
        std::cout << RED << "Нет узла с номером " << start << RESET << std::endl;
        return ;
    }
    std::cout << MAGENTA << "Список вершин в порядке обхода:" << RESET << std::endl;
    for (int number : way) {
        std::cout << GREEN << number << " ";
    }
    std::cout << RESET << std::endl;
}


void s21::ConsoleUI::BFS(s21::Graph &graph) {
    s21::GraphAlgorithms ga;
    int start;

    if (!graph.init) {
        std::cout << RED << "Требуется загрузить граф" << RESET << std::endl;
        return ;
    }
    std::cout << MAGENTA << "Введите стартувую вершину" << RESET << std::endl;
    std::cin >> start;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::vector<int> way = ga.breadthFirstSearch(graph, start);
    if (way.size() == 0) {
        std::cout << RED << "Нет узла с номером " << start << RESET << std::endl;
        return ;
    }
    std::cout << MAGENTA << "Список вершин в порядке обхода:" << RESET << std::endl;
    for (int number : way) {
        std::cout << GREEN << number << " ";
    }
    std::cout << RESET << std::endl;
}

void s21::ConsoleUI::min2(s21::Graph &graph) {
    if (!graph.init) {
        std::cout << RED << "Требуется загрузить граф" << RESET << std::endl;
        return ;
    }
    int start, final;
    std::cout << MAGENTA << "Введите стартувую вершину" << RESET << std::endl;
    std::cin >> start;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << MAGENTA << "Введите конечную вершину" << RESET << std::endl;
    std::cin >> final;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    s21::GraphAlgorithms ga;

    int res = ga.getShortestPathBetweenVertices(graph, start, final);
    if (res == -1) {
        std::cout << RED << "Нет узла с номером " << start << " или " << final << RESET << std::endl;
        return ;
    }
    if (res == -2) {
        std::cout << RED << "Не найден путь из " << start << " в " << final << RESET << std::endl;
        return ;
    }
    std::cout << MAGENTA << "Минимальное расстояние между этими вершинами" << RESET << std::endl;
    std::cout << GREEN << res << RESET << std::endl;


}

void s21::ConsoleUI::minAll(s21::Graph &graph) {
    if (!graph.init) {
        std::cout << RED << "Требуется загрузить граф" << RESET << std::endl;
        return ;
    }

    std::cout << MAGENTA << "Минимальное расстояние между всеми вершинами" << RESET << std::endl;
    s21::GraphAlgorithms ga;
    int **mat = ga.getShortestPathsBetweenAllVertices(graph);
    int s = graph.getSize();
    std::cout << GREEN;
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            std::cout << mat[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << RESET;
    for (int i = 0; i < s; ++i) {
        delete[] mat[i];
    }
    delete[] mat;
}

void s21::ConsoleUI::minTree(s21::Graph &graph) {
    if (!graph.init) {
        std::cout << RED << "Требуется загрузить граф" << RESET << std::endl;
        return ;
    }

    s21::GraphAlgorithms ga;
    std::cout << MAGENTA << "Минимальное островное дерево" << RESET << std::endl;
    int **mat = ga.getLeastSpanningTree(graph);
    int s = graph.getSize();
    std::cout << GREEN;
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            std::cout << mat[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << RESET;
    for (int i = 0; i < s; ++i) {
        delete[] mat[i];
    }
    delete[] mat;
    
}

void s21::ConsoleUI::TSM(s21::Graph &graph) {
    if (!graph.init) {
        std::cout << RED << "Требуется загрузить граф" << RESET << std::endl;
        return ;
    }
    s21::GraphAlgorithms ga;
    TsmResult res = ga.solveTravelingSalesmanProblem(graph);
    if (res.distance == 0.0) {
        std::cout << RED << "Для решения задачи коммивояжера граф должен быть связным" << RESET << std::endl;
        return ;
    }
    std::cout << MAGENTA << "Решение задачи коммивояжера" << RESET << std::endl;
    std::cout << MAGENTA << "Маршрут:" << RESET << std::endl;
    for (int number : res.vertices) {
        std::cout << GREEN << number << " ";
    }
    std::cout << std::endl;
    std::cout << MAGENTA << "Длина:" << RESET << std::endl;
    std::cout << GREEN << res.distance << RESET << std::endl;
}
