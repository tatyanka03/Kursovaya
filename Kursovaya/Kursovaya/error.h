
#ifndef ERROR_H
#define ERROR_H

#include <stdexcept>
#include <string>

// ���������� ��� ������ � �������� �������
class ListError : public std::runtime_error {
public:
    ListError(const std::string& message) : std::runtime_error(message) {}
};

// ����������, ���� ������ ����
class EmptyListError : public ListError {
public:
    EmptyListError() : ListError("������: ������ ����.") {}
};

// ����������, ���� ������� �� ������
class ElementNotFoundError : public ListError {
public:
    ElementNotFoundError() : ListError("������: ������� �� ������.") {}
};

// ����������, ���� ������ ������� �� �������
class IndexOutOfBoundsError : public ListError {
public:
    IndexOutOfBoundsError() : ListError("������: ������ ������� �� �������.") {}
};

#endif // ERROR_H
