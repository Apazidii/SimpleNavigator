#include "s21_graph_algorithms.h"

// Цветовые коды ANSI
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

// std::cout << RED << "Этот текст будет красным" << RESET << std::endl;



void help() {
    std::cout << GREEN << "help"    << RESET << "\t-\t" << YELLOW << "Вывод всех доступных комманд" << RESET << std::endl;
    std::cout << GREEN << "exit"    << RESET << "\t-\t" << YELLOW << "Выход из команды" << RESET << std::endl;
    std::cout << GREEN << "load"    << RESET << "\t-\t" << YELLOW << "Загрузка графа из файла" << RESET << std::endl;
    std::cout << GREEN << "DFS"     << RESET << "\t-\t" << YELLOW << "Обход графа в глубину" << RESET << std::endl;
    std::cout << GREEN << "BFS"     << RESET << "\t-\t" << YELLOW << "Обход графа в ширину" << RESET << std::endl;
    std::cout << GREEN << "min2"    << RESET << "\t-\t" << YELLOW << "Поиск минимального расстояния между двумя вершинами" << RESET << std::endl;
    std::cout << GREEN << "minAll"  << RESET << "\t-\t" << YELLOW << "Поиск минимального расстояния между всеми вершинами" << RESET << std::endl;
    std::cout << GREEN << "minTree" << RESET << "\t-\t" << YELLOW << "Поиск минимального островного дерева" << RESET << std::endl;
    std::cout << GREEN << "TSM"     << RESET << "\t-\t" << YELLOW << "Решение задачи комивояжера методом муравьиного алгоритма" << RESET << std::endl;
    std::cout << GREEN << "TSM2"    << RESET << "\t-\t" << YELLOW << "Решение задачи комивояжера методом полного перебора" << RESET << std::endl;
    std::cout << GREEN << "TSM3"    << RESET << "\t-\t" << YELLOW << "Решение задачи комивояжера методом ветвей и границ (работает только для полного графа)" << RESET << std::endl;


}

void load(s21::Graph &graph) {
    std::cout << MAGENTA << "Введите путь к файлу" << RESET << std::endl;
    std::string filename;
    std::getline(std::cin, filename);
    graph.loadGraphFromFile(filename);
}

void DFS(s21::Graph &graph) {
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


void BFS(s21::Graph &graph) {
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

void min2(s21::Graph &graph) {
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

void minAll(s21::Graph &graph) {
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

void minTree(s21::Graph &graph) {
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

void TSM(s21::Graph &graph) {
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

void TSM2(s21::Graph &graph) {
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

void TSM3(s21::Graph &graph) {
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

int main() {
    std::string cmd;

    s21::Graph graph;

    std::cout << YELLOW << "Добро пожаловать в SimpleNavigator. Введите команду (help для выводы всех команд)" << RESET << std::endl;
    while (cmd != "exit") {
        std::cout << CYAN << "SimpleNavigator" << RESET << ": ";
        std::getline(std::cin, cmd);


        if (cmd == "help")
            help();
        if (cmd == "load")
            load(graph);
        if (cmd == "DFS")
            DFS(graph);
        if (cmd == "BFS")
            BFS(graph);
        if (cmd == "min2")
            min2(graph);
        if (cmd == "minAll")
            minAll(graph);
        if (cmd == "minTree")
            minTree(graph);
        if (cmd == "TSM")
            TSM(graph);
        if (cmd == "TSM2")
            TSM2(graph);
        if (cmd == "TSM3")
            TSM3(graph);
    }
}