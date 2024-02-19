Создать очередь строковых значений, для реализации используя односвязные списки. Реализовать операции добавления (enqueue) и удаления(dequeue) элемента из очереди. Добавьте в очередь строки «one», «two», «three», «four», «five», «six», и распечатайте содержимое очереди. Удалите 2 элемента из очереди, затем добавьте в очередь строку «seven»и распечатайте очередь еще раз. Найдите количество строк начинающихся с букв «f» или «t».
Решение:
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");
    queue<string> queue;

    queue.push("one");
    queue.push("two");
    queue.push("three");
    queue.push("four");
    queue.push("five");
    queue.push("six");

    cout << "Изначальная очередь:" << endl;
    while (!queue.empty()) {
        cout << queue.front() << endl;
        queue.pop();
    }

    queue.push("one");
    queue.push("two");
    queue.push("three");
    queue.push("four");
    queue.push("five");
    queue.push("six");

    queue.pop();
    queue.pop();

    queue.push("seven");

    cout << "\nОчередь после изменений:" << endl;
    while (!queue.empty()) {
        cout << queue.front() << endl;
        queue.pop();
    }

    int count = 0;
    string str;
    for (int i = 0; i < 5; i++) {
        cin >> str;
        if (str[0] == 'f' || str[0] == 't') {
            count++;
        }
    }

    cout << "Количество строк начинающихся с букв 'f' или 't': " << count << endl;
    return 0;
}
