#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> numVec(N);
    map<int, int> freqMap;
    int sum = 0;

    for(int i = 0; i < N; i++) {
        cin >> numVec[i];
        sum += numVec[i];
        freqMap[numVec[i]]++;
    }

    sort(numVec.begin(), numVec.end());

    // 산술평균 처리, std::round 대신 직접 반올림 로직 구현
    int average = round((double)sum / N);
    cout << average << '\n';
    
    // 중앙값 출력
    cout << numVec[N / 2] << '\n';

    // 최빈값 처리
    int maxFrequency = 0;
    vector<int> modes;
    for (const auto& p : freqMap) {
        if (p.second > maxFrequency) {
            maxFrequency = p.second;
            modes.clear();
            modes.push_back(p.first);
        } else if (p.second == maxFrequency) {
            modes.push_back(p.first);
        }
    }

    // 최빈값이 여러 개인 경우 정렬 후 두 번째 값 선택
    if (modes.size() == 1) {
        cout << modes[0] << '\n';
    } else {
        sort(modes.begin(), modes.end());
        cout << modes[1] << '\n'; // 두 번째로 작은 최빈값 출력
    }

    // 범위 출력
    cout << numVec.back() - numVec.front() << '\n';

    return 0;
}
