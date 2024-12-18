#include <iostream>
#include <vector>
using namespace std;

class custom_hash {
private:
    int size;
    struct Node {
        string key;
        Node* next;

        Node(string& k) : key(k), next(nullptr) {}
    };
    vector<Node*> hashTable;

    int hash(const string& str) {
        long long hash = 0;
        long long prime = 31;
        long long mod = size;
        for (const auto& p : str) {
            hash = (hash * prime + static_cast<int>(p)) % mod;
        }
        return static_cast<int>(hash % mod);
    }

public:
    custom_hash(int tableSize) : size(tableSize) { hashTable.assign(size, nullptr); }

    void insert(string& str) {
        int _hash = hash(str);
        if (exist(str)) return;
        Node* n = new Node(str);
        n->next = hashTable[_hash];
        hashTable[_hash] = n;
    }

    bool exist(const string& str) {
        int _hash = hash(str);
        Node* temp = hashTable[_hash];

        while (temp) {
            if (temp->key == str) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void clear() {
        for (Node*& p : hashTable) {
            Node* current = p;
            while (current) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            p = nullptr;
        }
    }
};

int main() {
    int N;
    cin >> N;
    const string enterStr = "ENTER";
    custom_hash ch(5003);
    int cnt = 0;
    string temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (temp == enterStr) {
            ch.clear();
            continue;
        }

        if (!ch.exist(temp)) {
            cnt++;
            ch.insert(temp);
        }
    }
    cout << cnt;
}
