). Дано число (N > 0) и набор из N чисел. Создать стек, содержащий исходные числа (последнее число будет вершиной стека), и вывести указатель на его вершину.
Решение:
#include <iostream>
#include <stack>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int N;
    cout << "Введите число (N > 0): ";
    cin >> N;

    if (N <= 0) {
        cout << "Число должно быть больше 0." << endl;
        return 1;
    }

    stack<int> myStack;

    cout << "Введите числа: " << endl;
    for (int i = 0; i < N; ++i) {
        int number;
        cin >> number;
        myStack.push(number);
    }

    cout << "Указатель на вершину стека: " << myStack.top() << endl;

    return 0;
}
