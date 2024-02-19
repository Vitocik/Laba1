Создать линейный однонаправленный список из вещественных чисел. Определить количество элементов списка со значениями больше 7.
Решение:
#include <iostream>
using namespace std;

struct Node {
    double data;
    Node* next;

    Node(double value) : data(value), next(nullptr) {}
};

int countBol(Node* head) {
    int count = 0;
    while (head != nullptr) {
        if (head->data > 7) {
            count++;
        }
        head = head->next;
    }
    return count;
}

int main() {
    setlocale(LC_ALL, "Ru");
    Node* head = new Node(2);
    head->next = new Node(10);
    head->next->next = new Node(4);
    head->next->next->next = new Node(12);

    int result = countBol(head);

    cout << "Количество элементов больших 7: " << result << endl;

    return 0;
}
