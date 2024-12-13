
#ifndef ERROR_H
#define ERROR_H

#include <stdexcept>
#include <string>

// Исключение для работы с ошибками списков
class ListError : public std::runtime_error {
public:
    ListError(const std::string& message) : std::runtime_error(message) {}
};

// Исключение, если список пуст
class EmptyListError : public ListError {
public:
    EmptyListError() : ListError("Ошибка: список пуст.") {}
};

// Исключение, если элемент не найден
class ElementNotFoundError : public ListError {
public:
    ElementNotFoundError() : ListError("Ошибка: элемент не найден.") {}
};

// Исключение, если индекс выходит за пределы
class IndexOutOfBoundsError : public ListError {
public:
    IndexOutOfBoundsError() : ListError("Ошибка: индекс выходит за пределы.") {}
};

#endif // ERROR_H
