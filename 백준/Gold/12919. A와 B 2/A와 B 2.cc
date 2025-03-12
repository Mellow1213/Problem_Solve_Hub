#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int answer = 0;

void canTransform(string s, string t) {
    if (s.size() > t.size()) return;  // 더 길어지면 불가능
    if (s == t) { // 변환 성공
        answer = 1;
        return;
    }

    if (t.front() == t.back()) {
        if (t.back() == 'A') { // A A → pop_back()
            t.pop_back();
            canTransform(s, t);
        } else { // B B → 뒤집고 pop_back()
            reverse(t.begin(), t.end());
            t.pop_back();
            canTransform(s, t);
        }
    } else { // 앞, 뒤가 다른 경우 (B A만 가능)
        if (t.back() == 'A' && t.front() == 'B') { 
            string temp = t;
            temp.pop_back();
            canTransform(s, temp);

            reverse(t.begin(), t.end());
            t.pop_back();
            canTransform(s, t);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string S, T;
    cin >> S >> T;

    canTransform(S, T);
    cout << answer << "\n";

    return 0;
}
