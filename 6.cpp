Создать циклический двунаправленный список из целых чисел. Удалить из списка последний элемент со значением меньшим 15.
Решение:
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void addNode(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            head->next = tail;
            tail->prev = head;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            tail->next = head;
            head->prev = tail;
        }
    }

    void delLastLessThan15() {
        if (head == nullptr) {
            return;
        }
        Node* curr = tail;
        while (curr->data >= 15 && curr != head) {
            curr = curr->prev;
        }
        if (curr->data < 15) {
            Node* prevNode = curr->prev;
            Node* nextNode = curr->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            delete curr;
            tail = prevNode;
            head->prev = tail;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "Список пуст" << endl;
            return;
        }

        Node* curr = head;
        do {
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != head);
        cout << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Ru");
    LinkedList list;
    list.addNode(12);
    list.addNode(20);
    list.addNode(8);
    list.addNode(32);

    cout << "Начальный список: ";
    list.display();

    list.delLastLessThan15();

    cout << "Список после удаления последнего числа, меньшего 15: ";
    list.display();

    return 0;
}
