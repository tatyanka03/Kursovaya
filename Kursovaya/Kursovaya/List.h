// list.h
#ifndef LIST_H
#define LIST_H

#include <vector>
#include <iostream>
#include <algorithm> // ��� ����������
#include "error.h" // ���������� ��������� ������

// ������� ����� ��� ������
class BaseList {
protected:
    std::vector<int> elements;  // ������ ��� �������� ���������

public:
    virtual ~BaseList() = default;

    // ����� ��� ���������� ��������
    virtual void add(int value) {
        elements.push_back(value);
    }

    // ����� ��� �������� �������� �� �������
    virtual void remove(int index) {
        if (index < 0 || index >= elements.size()) {
            throw IndexOutOfBoundsError();
        }
        elements.erase(elements.begin() + index);
    }

    // ����� ��� ������ ���� ��������� ������
    virtual void print() const {
        if (elements.empty()) {
            throw EmptyListError();
        }
        for (int value : elements) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    // �������� ������ ������
    virtual int size() const {
        return elements.size();
    }
};

// ����� ��� ��������� ������, ������� ����������� �� BaseList
class NumericList : public BaseList {
public:
    // ���������� ������
    void sortList() {
        std::sort(elements.begin(), elements.end());
    }

    // �������� ������������ ��������
    int getMax() const {
        if (elements.empty()) {
            throw EmptyListError();
        }
        return *std::max_element(elements.begin(), elements.end());
    }

    // �������� ����������� ��������
    int getMin() const {
        if (elements.empty()) {
            throw EmptyListError();
        }
        return *std::min_element(elements.begin(), elements.end());
    }

    // �������������� ������� ��� ������ ������������� ��������
    bool findElement(int value) const {
        return std::find(elements.begin(), elements.end(), value) != elements.end();
    }
};

#endif // LIST_H
