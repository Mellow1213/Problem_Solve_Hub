#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> sequence(n); // 주어진 수열을 저장할 벡터
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }

    stack<int> s;
    vector<char> result; // 연산 결과를 저장할 벡터
    int current = 1; // 현재 수열의 위치를 나타내는 변수

    for (int num : sequence) {
        while (current <= num) { // 현재 수열의 숫자가 주어진 수열의 숫자와 같아질 때까지 반복
            s.push(current);
            result.push_back('+');
            ++current;
        }

        if (s.top() == num) { // 스택의 top이 주어진 수열의 숫자와 같으면 pop
            s.pop();
            result.push_back('-');
        } else {
            cout << "NO\n"; // 수열을 만들 수 없는 경우
            return 0;
        }
    }

    // 연산 순서 출력
    for (char op : result) {
        cout << op << "\n";
    }

    return 0;
}
