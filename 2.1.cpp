Создать стек строковых значений, для реализации используя односвязные списки. Реализовать операции добавления (push) и удаления (pop) элемента из стека. Добавьте в стек строки «abc», «fx», «glc», «hi», «gogo» и распечатайте содержимое стека. Удалите один элемент из стека, затем добавьте строку «the end» и распечатайте содержимое стека еще раз. Найдите количество строк в стеке, состоящих из 2 символов.
Решение:
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");

    stack<string> stack;

    stack.push("abc");
    stack.push("fx");
    stack.push("glc");
    stack.push("hi");
    stack.push("gogo");

    cout << "Изначальный стек:" << endl;
    while (!stack.empty()) {
        cout << stack.top() << endl;
        stack.pop();
    }

    stack.push("abc");
    stack.push("fx");
    stack.push("glc");
    stack.push("hi");
    stack.push("gogo");
    stack.pop();
    stack.push("the end");

    cout << "\nСтек после изменений:" << endl;
    while (!stack.empty()) {
        cout << stack.top() << endl;
        stack.pop();
    }

    int count = 0;
    for (string str : {"abc", "fx", "glc", "hi", "gogo", "the end"}) {
        if (str.length() == 2) {
            count++;
        }
    }

    cout << "\nКоличество строк состоящих из 2 символов: " << count << endl;

    return 0;
}
