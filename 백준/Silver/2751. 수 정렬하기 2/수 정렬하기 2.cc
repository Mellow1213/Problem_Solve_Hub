#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    int v[N];

    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v, v + N);

    for(int i = 0; i < N; i++) {
        cout << v[i] << '\n';
    }

    return 0;
}
