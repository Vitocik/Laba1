Создать линейный однонаправленный список из вещественных чисел. Вставить в список число 1.5 после каждого элемента с отрицательным значением.
Решение:
#include <iostream>
using namespace std;
struct Node {
    float data;
    Node* next;
};

void VstavPosNeg(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data < 0) {
            Node* newNode = new Node;
            newNode->data = 1.5;
            newNode->next = current->next;
            current->next = newNode;
            current = current->next->next;
        }
        else {
            current = current->next;
        }
    }
}

void Cpicok(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Ru");
    Node* head = new Node;
    Node* second = new Node;
    Node* third = new Node;

    head->data = -2;
    head->next = second;

    second->data = 3;
    second->next = third;

    third->data = -4;
    third->next = nullptr;

    cout << "Изначальный список:" << endl;
    Cpicok(head);

    VstavPosNeg(head);

    cout << "Список после вставки:" << endl;
    Cpicok(head);

    return 0;
}
