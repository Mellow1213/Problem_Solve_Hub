#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;  // 포인트 카드에 2N개의 칸이 있고 M장의 포인트 카드를 가지고 있음

    vector<pair<int, int>> card;
    int cnt = 0;  // 경품을 얻을 수 있는 카드의 개수를 카운트

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;  // A개의 당첨도장와 B개의 꽝 도장이 찍혀있음
        if (A < N) {
            card.push_back({A, B});
        } else {
            cnt++;
        }
    }

    // 내림차순 정렬
    sort(card.begin(), card.end(), greater<pair<int, int>>());

    int result = 0;
    if ((M - 1) == cnt) {
        cout << 0 << endl;
    } else {
        for (int i = 0; i < M - 1 - cnt; i++) {
            result += (N - card[i].first);
        }
        cout << result << endl;
    }

    return 0;
}