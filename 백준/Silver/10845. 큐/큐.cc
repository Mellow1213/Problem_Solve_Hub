#include <iostream>
#include <string>
using namespace std;

class Queue {
private:
    int front;
    int back;
    int size;
    int* queue;
public:
    Queue(int size) {
        queue = new int[size];
        this->size = size;
        this->front = 0;
        this->back = -1; // back을 -1로 초기화
    }
    ~Queue() {
        delete[] queue;
    }
    void Push(int X);
    void Pop();
    void Size();
    void Empty();
    void Front();
    void Back();
};

void Queue::Push(int X) {
    if(back - front + 1 == size) {
        // 큐가 가득 찼을 경우 처리하지 않음
        return;
    }
    back++;
    queue[back] = X;
}

void Queue::Pop() {
    if(front > back) {
        cout << -1 << '\n';
        return;
    }
    cout << queue[front++] << '\n';
}

void Queue::Size() {
    cout << back - front + 1 << '\n';
}

void Queue::Empty() {
    cout << (front > back ? 1 : 0) << '\n';
}

void Queue::Front() {
    if(front > back) {
        cout << -1 << '\n';
    } else {
        cout << queue[front] << '\n';
    }
}

void Queue::Back() {
    if(front > back) {
        cout << -1 << '\n';
    } else {
        cout << queue[back] << '\n';
    }
}

int main() {
    int N;
    cin >> N;
    Queue q(N);

    for(int i = 0; i < N; i++) {
        string command;
        cin >> command;
        if(command == "push") {
            int num;
            cin >> num;
            q.Push(num);
        } else if(command == "pop") {
            q.Pop();
        } else if(command == "size") {
            q.Size();
        } else if(command == "empty") {
            q.Empty();
        } else if(command == "front") {
            q.Front();
        } else if(command == "back") {
            q.Back();
        }
    }
}
