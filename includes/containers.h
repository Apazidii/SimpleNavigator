#ifndef CONTAINERS_H
#define CONTAINERS_H

#include <iostream>
#include <vector>

namespace s21 {

    template <typename T>
    class BaseContainer {
        protected:
            std::vector<T> data;
        public:
            virtual void init() = 0;
            virtual void push(const T& value) = 0;
            virtual T pop() = 0;
            virtual T peek() = 0;
            virtual std::size_t size() = 0;
    };

    template <typename T>
    class Stack: public BaseContainer<T> {
    public:
        void init() {
            this->data.clear();
        }

        void push(const T& value) {
            this->data.push_back(value);
        }

        T pop() {
            if (this->data.empty()) {
                throw std::runtime_error("Стек пуст");
            }
            T value = this->data.back();
            this->data.pop_back();
            return value;
        }

        T peek() {
            if (this->data.empty()) {
                throw std::runtime_error("Стек пуст");
            }
            return this->data.back();
        }

        std::size_t size() {
            return this->data.size();
        }
    };

    template <typename T>
    class Queue: public BaseContainer<T> {
    public:
        void init() {
            this->data.clear();
        }

        void push(const T& value) {
            this->data.push_back(value);
        }

        T pop() {
            if (this->data.empty()) {
                throw std::runtime_error("Очередь пуста");
            }
            T value = this->data.front();
            this->data.erase(this->data.begin());
            return value;
        }

        T peek() {
            if (this->data.empty()) {
                throw std::runtime_error("Очередь пуста");
            }
            return this->data.front();
        }

        std::size_t size() {
            return this->data.size();
        }
    };
}

#endif