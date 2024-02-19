Создать линейный однонаправленный список из целых чисел. Вставить в список число 15 после каждого элемента, по модулю меньшего 2.
Решение:
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

void vstavAfter(Node* prev_node) {
    if (prev_node == nullptr)
        return;

    Node* new_node = new Node(15);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void vstavNumberAfterLessThen2(Node* head) {
    if (head == nullptr)
        return;

    Node* current = head;
    while (current != nullptr) {
        if (current->data < 2) {
            vstavAfter(current);
            current = current->next;
        }
        current = current->next;
    }
}

void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    Node* head = new Node(13);
    head->next = new Node(-3);

    cout << "Изначальный список: ";
    displayList(head);

    vstavNumberAfterLessThen2(head);

    cout << "Список после вставки: ";
    displayList(head);

    return 0;
}
