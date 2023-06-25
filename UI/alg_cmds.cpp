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
    std::cout << MAGENTA << "Решение задачи комивояжера" << RESET << std::endl;
    std::cout << MAGENTA << "Маршрут:" << RESET << std::endl;
    for (int number : res.vertices) {
        std::cout << GREEN << number << " ";
    }
    std::cout << std::endl;
    std::cout << MAGENTA << "Длина:" << RESET << std::endl;
    std::cout << GREEN << res.distance << RESET << std::endl;
}

void s21::ConsoleUI::TSM2(s21::Graph &graph) {
    if (!graph.init) {
        std::cout << RED << "Требуется загрузить граф" << RESET << std::endl;
        return ;
    }
    s21::GraphAlgorithms ga;
    TsmResult res = ga.solveTravelingSalesmanProblem2(graph);
    std::cout << MAGENTA << "Решение задачи комивояжера" << RESET << std::endl;
    std::cout << MAGENTA << "Маршрут:" << RESET << std::endl;
    for (int number : res.vertices) {
        std::cout << GREEN << number << " ";
    }
    std::cout << std::endl;
    std::cout << MAGENTA << "Длина:" << RESET << std::endl;
    std::cout << GREEN << res.distance << RESET << std::endl;
}

void s21::ConsoleUI::TSM3(s21::Graph &graph) {
    if (!graph.init) {
        std::cout << RED << "Требуется загрузить граф" << RESET << std::endl;
        return ;
    }
    s21::GraphAlgorithms ga;
    TsmResult res = ga.solveTravelingSalesmanProblem3(graph);
    if (res.distance == 0.0) {
        std::cout << RED << "Граф должен быть полным" << RESET << std::endl;
        return ;
    }
    std::cout << MAGENTA << "Решение задачи комивояжера" << RESET << std::endl;
    std::cout << MAGENTA << "Маршрут:" << RESET << std::endl;
    for (int number : res.vertices) {
        std::cout << GREEN << number << " ";
    }
    std::cout << std::endl;
    std::cout << MAGENTA << "Длина:" << RESET << std::endl;
    std::cout << GREEN << res.distance << RESET << std::endl;
}



template<typename Function, typename Graph>
void MeasureExecutionTime(Function func, Graph &graph, int N)
{
    high_resolution_clock::time_point startTime = high_resolution_clock::now();

    for (int i = 0; i < N; ++i)
    {
        (func)(graph); // Вызываем переданный метод класса
    }

    high_resolution_clock::time_point endTime = high_resolution_clock::now();
    milliseconds duration = duration_cast<milliseconds>(endTime - startTime);

    std::cout << "Время выполнения: " << duration.count() << " мс" << std::endl;
}


void s21::ConsoleUI::CompareTSM(s21::Graph &graph) {
    if (!graph.init) {
        std::cout << RED << "Требуется загрузить граф" << RESET << std::endl;
        return ;
    }
    int N;
    std::cout << MAGENTA << "Введите количество замеров для функций" << RESET << std::endl;
    std::cin >> N;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    s21::GraphAlgorithms ga;
    auto solveTSP1 = std::bind(&s21::GraphAlgorithms::solveTravelingSalesmanProblem, &ga, std::placeholders::_1);
    auto solveTSP2 = std::bind(&s21::GraphAlgorithms::solveTravelingSalesmanProblem2, &ga, std::placeholders::_1);
    auto solveTSP3 = std::bind(&s21::GraphAlgorithms::solveTravelingSalesmanProblem3, &ga, std::placeholders::_1);

    std::cout << MAGENTA << "Муравьиный алгоритм" << RESET << std::endl;
    std::cout << GREEN;
    MeasureExecutionTime(solveTSP1, graph, N);
    std::cout << RESET;

    std::cout << MAGENTA << "Алгоритм полного перебора" << RESET << std::endl;
    std::cout << GREEN;
    MeasureExecutionTime(solveTSP2, graph, N);
    std::cout << RESET;

    if (ga.checkFullGraph(graph)) {
        std::cout << MAGENTA << "Алгоритм ветвей и границ" << RESET << std::endl;
        std::cout << GREEN;
        MeasureExecutionTime(solveTSP3, graph, N);
        std::cout << RESET;
    }

}
