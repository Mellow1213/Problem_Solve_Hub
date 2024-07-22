#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    unordered_set<int> uniqueStreaks;  // 고유한 최대 연속 중단 일수
    vector<pair<int, string>> participants;  // 최대 연속 중단 일수와 이름을 저장할 리스트

    for (int i = 0; i < N; i++) {
        string streak, name;
        
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            streak += c;
        }
        cin >> name;

        int maxStreak = 0;  // 최대 연속 중단 일수 확인
        int currentStreak = 0;
        for (char c : streak) {
            if (c == '.') {  // 문제를 풀지 않았으면
                currentStreak++;  // 현재 연속 중단 일수 증가
            } else {  // 문제를 풀었으면
                currentStreak = 0;  // 연속 중단 일수 초기화
            }
            maxStreak = max(maxStreak, currentStreak);  // 최대 연속 중단 일수 갱신
        }

        uniqueStreaks.insert(maxStreak);  // 고유한 최대 연속 중단 일수 추가
        participants.push_back({maxStreak, name});  // 최대 연속 중단 일수와 이름 저장
    }

    cout << uniqueStreaks.size() << '\n';
    for (const auto& p : participants) {
        cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}