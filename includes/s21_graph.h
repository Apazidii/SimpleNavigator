#ifndef S21_GRAPH_H
# define S21_GRAPH_H

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>


namespace s21 {

    class Graph {
        private:
            int **matrix = nullptr;
            int     size;
            std::string name = "graphname";



        private:
            std::string numberToString(int num);
            bool typeGraph();
            void freeMatrix();


        public:
            ~Graph();
            bool init = false;


        //getters
        public:
            int **getMatrix();
            int getSize();

        public:
            int *getNodes(int node);

        public:
            void loadGraphFromFile(std::string filename);
            void exportGraphToDot(std::string filename);

    };

}

#endif