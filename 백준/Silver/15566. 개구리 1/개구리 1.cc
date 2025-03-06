#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Favorite {
    int food, hobby, family, philosophy;
};

struct Frog {
    Favorite favor;
    int favoriteLotus[2];
};

struct Log {
    int endA, endB, subject;
};

int N, M;
vector<Frog> frogs;
vector<Log> logs;
vector<int> lotus; // 각 연꽃에 배치된 개구리의 인덱스 (-1이면 비어있음)

bool checkLogs() {
    for (const auto& lg : logs) {
        int frogA = lotus[lg.endA];
        int frogB = lotus[lg.endB];
        if (frogA == -1 || frogB == -1) continue; // 아직 배치되지 않은 경우
        int subject = lg.subject;
        if (subject == 1 && frogs[frogA].favor.food != frogs[frogB].favor.food) return false;
        if (subject == 2 && frogs[frogA].favor.hobby != frogs[frogB].favor.hobby) return false;
        if (subject == 3 && frogs[frogA].favor.family != frogs[frogB].favor.family) return false;
        if (subject == 4 && frogs[frogA].favor.philosophy != frogs[frogB].favor.philosophy) return false;
    }
    return true;
}

bool backtrack(int idx) {
    if (idx == N) {
        if (checkLogs()) {
            cout << "YES\n";
            for (int i = 0; i < N; i++) {
                cout << lotus[i] + 1 << ' '; // 0-based index를 1-based로 변환
            }
            cout << '\n';
            return true;
        }
        return false;
    }

    for (int i = 0; i < 2; i++) {
        int lotusIdx = frogs[idx].favoriteLotus[i] - 1; // 1-based index를 0-based로 변환
        if (lotus[lotusIdx] == -1) { // 해당 연꽃이 비어있다면
            lotus[lotusIdx] = idx;
            if (backtrack(idx + 1)) return true;
            lotus[lotusIdx] = -1; // 백트래킹
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    frogs.resize(N);
    logs.resize(M);
    lotus.assign(N, -1);

    for (int i = 0; i < N; i++) {
        int t1, t2, t3, t4;
        cin >> t1 >> t2 >> t3 >> t4;
        frogs[i].favor = {t1, t2, t3, t4};
    }

    for (int i = 0; i < N; i++) {
        int l1, l2;
        cin >> l1 >> l2;
        frogs[i].favoriteLotus[0] = l1;
        frogs[i].favoriteLotus[1] = l2;
    }

    for (int i = 0; i < M; i++) {
        int a, b, sub;
        cin >> a >> b >> sub;
        logs[i] = {a - 1, b - 1, sub}; // 1-based index를 0-based로 변환
    }

    if (!backtrack(0)) {
        cout << "NO\n";
    }

    return 0;
}
