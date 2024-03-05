#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> rank(N);
        map<int, int> result;

        for (int i = 0; i < N; i++) {
            cin >> rank[i];
            result[rank[i]]++;
        }

        map<int, int> scoreMap, tempMap;
        vector<int> fifthGoalIdx(N + 1, 0);
        int score = 1;

        for (int element : rank) {
            if (result[element] >= 6) {
                tempMap[element]++;

                if (tempMap[element] <= 4) {
                    scoreMap[element] += score;
                }

                if (tempMap[element] == 5) {
                    fifthGoalIdx[element] = score;
                }
                score++;
            }
        }

        vector<int> keyData;
        for (auto const& pair : scoreMap) {
            keyData.push_back(pair.first);
        }

        sort(keyData.begin(), keyData.end(), [&scoreMap, &fifthGoalIdx](int x, int y) {
            if (scoreMap[x] == scoreMap[y]) {
                return fifthGoalIdx[x] < fifthGoalIdx[y];
            }
            return scoreMap[x] < scoreMap[y];
        });

        cout << keyData.front() << '\n';
    }
    return 0;
}
