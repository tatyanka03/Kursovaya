// list.h
#ifndef LIST_H
#define LIST_H

#include <vector>
#include <iostream>
#include <algorithm> // для сортировки
#include "error.h" // Подключаем обработку ошибок

// Базовый класс для списка
class BaseList {
protected:
    std::vector<int> elements;  // Вектор для хранения элементов

public:
    virtual ~BaseList() = default;

    // Метод для добавления элемента
    virtual void add(int value) {
        elements.push_back(value);
    }

    // Метод для удаления элемента по индексу
    virtual void remove(int index) {
        if (index < 0 || index >= elements.size()) {
            throw IndexOutOfBoundsError();
        }
        elements.erase(elements.begin() + index);
    }

    // Метод для печати всех элементов списка
    virtual void print() const {
        if (elements.empty()) {
            throw EmptyListError();
        }
        for (int value : elements) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    // Получить размер списка
    virtual int size() const {
        return elements.size();
    }
};

// Класс для числового списка, который наследуется от BaseList
class NumericList : public BaseList {
public:
    // Сортировка списка
    void sortList() {
        std::sort(elements.begin(), elements.end());
    }

    // Получить максимальное значение
    int getMax() const {
        if (elements.empty()) {
            throw EmptyListError();
        }
        return *std::max_element(elements.begin(), elements.end());
    }

    // Получить минимальное значение
    int getMin() const {
        if (elements.empty()) {
            throw EmptyListError();
        }
        return *std::min_element(elements.begin(), elements.end());
    }

    // Дополнительная функция для поиска определенного элемента
    bool findElement(int value) const {
        return std::find(elements.begin(), elements.end(), value) != elements.end();
    }
};

#endif // LIST_H
