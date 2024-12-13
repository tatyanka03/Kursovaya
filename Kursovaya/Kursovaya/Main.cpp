#include <iostream>
#include "List.h"  // ���������� ������ �� ��������
#include "error.h" // ���������� ��������� ������

int main() {
    setlocale(LC_ALL, "ru");
    NumericList list;  // ������� ������ ������
    int choice;

    do {
        std::cout << "\n����:\n"
            << "1. �������� �������\n"
            << "2. ������� �������\n"
            << "3. �������� ��� ��������\n"
            << "4. ����� ������������ ��������\n"
            << "5. ����� ����������� ��������\n"
            << "6. �������� ������\n"
            << "7. ����� �������\n"
            << "0. �����\n"
            << "�������� ��������: ";
        std::cin >> choice;

        try {
            switch (choice) {
            case 1: {
                std::cout << "������� �������: ";
                int value;
                std::cin >> value;
                list.add(value);  // ��������� ������� � ������
                std::cout << "������� ��������.\n";
                break;
            }
            case 2: {
                std::cout << "������� ������ ��� ��������: ";
                int index;
                std::cin >> index;
                list.remove(index);  // ������� ������� �� �������
                std::cout << "������� ������.\n";
                break;
            }
            case 3:
                std::cout << "�������� ������: ";
                list.print();  // �������� ��� �������� ������
                break;
            case 4:
                std::cout << "������������ ��������: " << list.getMax() << std::endl;
                break;
            case 5:
                std::cout << "����������� ��������: " << list.getMin() << std::endl;
                break;
            case 6:
                list = NumericList();  // ����������� ������ ������ ��� �������
                std::cout << "������ ������.\n";
                break;
            case 7: {
                std::cout << "������� ������� ��� ������: ";
                int value;
                std::cin >> value;
                if (list.findElement(value)) {
                    std::cout << "������� ������ � ������.\n";
                }
                else {
                    std::cout << "������� �� ������.\n";
                }
                break;
            }
            case 0:
                std::cout << "����� �� ���������.\n";
                break;
            default:
                std::cout << "�������� �����, ���������� �����.\n";
            }
        }
        catch (const ListError& e) {
            std::cout << "������: " << e.what() << std::endl;
        }

    } while (choice != 0);

    return 0;
}
