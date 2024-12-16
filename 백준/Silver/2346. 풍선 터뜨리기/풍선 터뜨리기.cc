#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int idx;
    int value;
    Node* next;
    Node* prev;
    Node(int i, int v) : idx(i), value(v), next(nullptr), prev(nullptr) {}
};

class Balloon {
    int cnt;
    Node* firstPtr;
    Node* currentPtr;
public:
    Balloon(int N, vector<int>& arr) : cnt(N) {
        currentPtr = new Node(1, arr[0]);
        firstPtr = currentPtr;
        for (int i = 2; i <= N; i++) {
            currentPtr->next = new Node(i, arr[i - 1]);
            currentPtr->next->prev = currentPtr;
            currentPtr = currentPtr->next;
        }
        currentPtr->next = firstPtr;
        firstPtr->prev = currentPtr;
        currentPtr = firstPtr;
    }
    
    void move(bool isMinus) {
        currentPtr = isMinus ? currentPtr->prev : currentPtr->next;
    }

    void move(int n) {
        if (n < 0) {
            n = -n;
            for (int i = 0; i < n; i++) {
                move(true);
            }
        } else {
for (int i = 0; i < n-1; i++) {
                move(false);
            }
        }
    }

    void pop() {
        int nextMove = currentPtr->value;
        cout << currentPtr->idx << ' ';
        Node* tempPtr = currentPtr->prev;
        tempPtr->next = currentPtr->next;
        tempPtr->next->prev = tempPtr;
        delete currentPtr;
        currentPtr = tempPtr->next;
        move(nextMove);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    Balloon balloon(N, arr);

    for (int i = 0; i < N; i++) {
        balloon.pop();
    }

    return 0;
}
