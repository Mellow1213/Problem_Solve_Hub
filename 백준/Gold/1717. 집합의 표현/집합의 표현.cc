#include <iostream>
#include <vector>
using namespace std;

static int Min(int a, int b) {
    return (a < b ? a : b);
}
class NumberSet {
    vector<int> parent;

public:
    NumberSet(int n) : parent(n + 1) {
        for (int i = 0; i <= n; ++i)
            parent[i] = i;
    }

    int Find(int x) {
        if (parent[x] != x)
            parent[x] = Find(parent[x]); // 경로 압축
        return parent[x];
    }

    void Add(int a, int b) {
        a = Find(a);
        b = Find(b);
        if (a != b) {
            parent[b] = a; // 또는 parent[a] = b;
        }
    }

    string Search(int a, int b) {
        return (Find(a) == Find(b) ? "YES\n" : "NO\n");
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    NumberSet numSet(N);
    
    for(int i=0; i<M; i++) {
        int command, a, b;
        cin >> command >> a >> b;
        switch(command) {
            case 0:
                numSet.Add(a, b);
                break;
            case 1:
                cout << numSet.Search(a, b);
                break;
        }
    }
}