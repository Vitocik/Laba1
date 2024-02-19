Создать линейный двунаправленный список из символов. Удалить из списка элемент после каждого символа &.
Решение:
#include <iostream>
using namespace std;
struct Node {
    char data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insert(char value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            newNode->prev = nullptr;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void removeAfterAmp() {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == '&') {
                Node* temp = current->next;
                if (temp != nullptr) {
                    current->next = temp->next;
                    if (temp->next != nullptr) {
                        temp->next->prev = current;
                    }
                    else {
                        tail = current;
                    }
                    delete temp;
                }
            }
            current = current->next;
        }
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Ru");
    DoublyLinkedList list;
    list.insert('a');
    list.insert('&');
    list.insert('b');
    list.insert('c');
    list.insert('d');
    list.insert('&');
    list.insert('e');

    cout << "Начальный список:" << endl;
    list.display();

    list.removeAfterAmp();

    cout << "Список после удаления элементов после '&':" << endl;
    list.display();

    return 0;
}
