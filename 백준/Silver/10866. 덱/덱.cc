#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int data = 0, Node* prev = nullptr, Node* next = nullptr)
        : data(data), prev(prev), next(next) {}
};

class Deque {
private:
    Node* front;
    Node* rear;
    int size;

public:
    Deque() : front(nullptr), rear(nullptr), size(0) {}

    ~Deque() {
        while (!isEmpty()) {
            removeFront();
        }
    }

    bool isEmpty() const {
        return size == 0;
    }

    void addFront(int data) {
        Node* newNode = new Node(data, nullptr, front);
        if (isEmpty()) {
            rear = newNode;
        } else {
            front->prev = newNode;
        }
        front = newNode;
        size++;
    }

    void addRear(int data) {
        Node* newNode = new Node(data, rear, nullptr);
        if (isEmpty()) {
            front = newNode;
        } else {
            rear->next = newNode;
        }
        rear = newNode;
        size++;
    }

    int removeFront() {
        if (isEmpty()) {
            return -1;
        }
        Node* temp = front;
        int data = temp->data;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        } else {
            front->prev = nullptr;
        }
        delete temp;
        size--;
        return data;
    }

    int removeRear() {
        if (isEmpty()) {
            return -1;
        }
        Node* temp = rear;
        int data = temp->data;
        rear = rear->prev;
        if (rear == nullptr) {
            front = nullptr;
        } else {
            rear->next = nullptr;
        }
        delete temp;
        size--;
        return data;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return front->data;
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return rear->data;
    }

    int getSize() const {
        return size;
    }
};

int main() {
    int N;
    cin >> N;
    Deque dq;

    for (int i = 0; i < N; ++i) {
        string cmd;
        cin >> cmd;
        if (cmd == "push_front") {
            int x;
            cin >> x;
            dq.addFront(x);
        } else if (cmd == "push_back") {
            int x;
            cin >> x;
            dq.addRear(x);
        } else if (cmd == "pop_front") {
            cout << dq.removeFront() << "\n";
        } else if (cmd == "pop_back") {
            cout << dq.removeRear() << "\n";
        } else if (cmd == "size") {
            cout << dq.getSize() << "\n";
        } else if (cmd == "empty") {
            cout << dq.isEmpty() << "\n";
        } else if (cmd == "front") {
            cout << dq.getFront() << "\n";
        } else if (cmd == "back") {
            cout << dq.getRear() << "\n";
        }
    }

    return 0;
}
