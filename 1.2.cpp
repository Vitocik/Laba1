Создать очередь из вещественных чисел. Определить количество отрицательных чисел очереди. Организовать просмотр данных очереди.
Решение:
#include <iostream>
#include <queue>
using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");
    queue<double> numbers;

    // Добавляем элементы в очередь
    numbers.push(-5.5);
    numbers.push(-2.7);
    numbers.push(8.2);
    numbers.push(-4.9);
    numbers.push(12.2);

    // Переменная для хранения количества отрицательных чисел
    int negativeCount = 0;

    // Просмотр данных очереди
    cout << "Очередь элементов: ";
    while (!numbers.empty()) {
        cout << numbers.front() << " ";
        if (numbers.front() < 0) {
            negativeCount++;
        }
        numbers.pop();
    }

    cout << "\nКоличество отрицательных элементов в очереди: " << negativeCount << endl;

    return 0;
}
