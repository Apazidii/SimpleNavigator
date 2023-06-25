#ifndef UI_H
#define UI_H



#include "s21_graph_algorithms.h"
#include <chrono>
#include <functional> 
using namespace std::chrono;

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

namespace s21 {
    class ConsoleUI {
        public:
            void start();
        private:
            void help();
            void load(s21::Graph &graph);
            void print(s21::Graph &graph);
            void DFS(s21::Graph &graph);
            void BFS(s21::Graph &graph);
            void min2(s21::Graph &graph);
            void minAll(s21::Graph &graph);
            void minTree(s21::Graph &graph);
            void TSM(s21::Graph &graph);
            void TSM2(s21::Graph &graph);
            void TSM3(s21::Graph &graph);
            void CompareTSM(s21::Graph &graph);

    };
}


#endif