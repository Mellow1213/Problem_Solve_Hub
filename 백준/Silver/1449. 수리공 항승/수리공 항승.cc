#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, L;
    cin >> N >> L;
    vector<int> pos(N);
    
    for (int i = 0; i < N; i++) {
        cin >> pos[i];
    }

    sort(pos.begin(), pos.end());

    int answer = 0;
    double coverEnd = 0;

    for (int i = 0; i < N; i++) {
        if (pos[i] > coverEnd) {
            answer++;
            coverEnd = pos[i] - 0.5 + L;
        }
    }

    cout << answer;
}
