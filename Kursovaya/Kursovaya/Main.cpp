#include <iostream>
#include "List.h"  // Подключаем работу со списками
#include "error.h" // Подключаем обработку ошибок

int main() {
    setlocale(LC_ALL, "ru");
    NumericList list;  // Создаем объект списка
    int choice;

    do {
        std::cout << "\nМеню:\n"
            << "1. Добавить элемент\n"
            << "2. Удалить элемент\n"
            << "3. Показать все элементы\n"
            << "4. Найти максимальное значение\n"
            << "5. Найти минимальное значение\n"
            << "6. Очистить список\n"
            << "7. Найти элемент\n"
            << "0. Выход\n"
            << "Выберите действие: ";
        std::cin >> choice;

        try {
            switch (choice) {
            case 1: {
                std::cout << "Введите элемент: ";
                int value;
                std::cin >> value;
                list.add(value);  // Добавляем элемент в список
                std::cout << "Элемент добавлен.\n";
                break;
            }
            case 2: {
                std::cout << "Введите индекс для удаления: ";
                int index;
                std::cin >> index;
                list.remove(index);  // Удаляем элемент по индексу
                std::cout << "Элемент удален.\n";
                break;
            }
            case 3:
                std::cout << "Элементы списка: ";
                list.print();  // Печатаем все элементы списка
                break;
            case 4:
                std::cout << "Максимальное значение: " << list.getMax() << std::endl;
                break;
            case 5:
                std::cout << "Минимальное значение: " << list.getMin() << std::endl;
                break;
            case 6:
                list = NumericList();  // Пересоздаем объект списка для очистки
                std::cout << "Список очищен.\n";
                break;
            case 7: {
                std::cout << "Введите элемент для поиска: ";
                int value;
                std::cin >> value;
                if (list.findElement(value)) {
                    std::cout << "Элемент найден в списке.\n";
                }
                else {
                    std::cout << "Элемент не найден.\n";
                }
                break;
            }
            case 0:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный выбор, попробуйте снова.\n";
            }
        }
        catch (const ListError& e) {
            std::cout << "Ошибка: " << e.what() << std::endl;
        }

    } while (choice != 0);

    return 0;
}
