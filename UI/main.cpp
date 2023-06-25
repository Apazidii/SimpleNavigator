#include "UI.h"






void s21::ConsoleUI::help() {
    std::cout << GREEN << "help"    << RESET << "\t-\t" << YELLOW << "Вывод всех доступных комманд" << RESET << std::endl;
    std::cout << GREEN << "exit"    << RESET << "\t-\t" << YELLOW << "Выход из команды" << RESET << std::endl;
    std::cout << GREEN << "load"    << RESET << "\t-\t" << YELLOW << "Загрузка графа из файла" << RESET << std::endl;
    std::cout << GREEN << "print"    << RESET << "\t-\t" << YELLOW << "Вывод матрицы смежности графа" << RESET << std::endl;
    std::cout << GREEN << "DFS"     << RESET << "\t-\t" << YELLOW << "Обход графа в глубину" << RESET << std::endl;
    std::cout << GREEN << "BFS"     << RESET << "\t-\t" << YELLOW << "Обход графа в ширину" << RESET << std::endl;
    std::cout << GREEN << "min2"    << RESET << "\t-\t" << YELLOW << "Поиск минимального расстояния между двумя вершинами" << RESET << std::endl;
    std::cout << GREEN << "minAll"  << RESET << "\t-\t" << YELLOW << "Поиск минимального расстояния между всеми вершинами" << RESET << std::endl;
    std::cout << GREEN << "minTree" << RESET << "\t-\t" << YELLOW << "Поиск минимального островного дерева" << RESET << std::endl;
    std::cout << GREEN << "TSM"     << RESET << "\t-\t" << YELLOW << "Решение задачи комивояжера методом муравьиного алгоритма" << RESET << std::endl;
    std::cout << GREEN << "TSM2"    << RESET << "\t-\t" << YELLOW << "Решение задачи комивояжера методом полного перебора" << RESET << std::endl;
    std::cout << GREEN << "TSM3"    << RESET << "\t-\t" << YELLOW << "Решение задачи комивояжера методом ветвей и границ (работает только для полного графа)" << RESET << std::endl;


}

void s21::ConsoleUI::load(s21::Graph &graph) {
    std::cout << MAGENTA << "Введите путь к файлу" << RESET << std::endl;
    std::string filename;
    std::getline(std::cin, filename);
    graph.loadGraphFromFile(filename);
}

void s21::ConsoleUI::print(s21::Graph &graph) {
    if (!graph.init) {
        std::cout << RED << "Требуется загрузить граф" << RESET << std::endl;
        return ;
    }
    int **mat = graph.getMatrix();
    int s = graph.getSize();

    std::cout << MAGENTA << "Матрица смежности загруженного графа" << RESET << std::endl;

    std::cout << GREEN;
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            std::cout << mat[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << RESET;

}


void s21::ConsoleUI::start() {
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
        if (cmd == "print")
            print(graph);
        if (cmd == "compareTSM")
            CompareTSM(graph);
    }
}

int main() {
    s21::ConsoleUI cui;
    cui.start();
    return 0;
}