#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    vector<int> heights(N);  // 탑의 높이를 저장하는 벡터
    vector<int> answer(N, 0);  // 답을 저장하는 벡터, 초기값 0
    stack<int> cacheStack;  // 비교를 위한 스택

    // 탑의 높이를 입력받아 벡터에 저장
    for (int i = 0; i < N; ++i) {
        cin >> heights[i];
    }

    // 탑을 역순으로 처리
    for (int i = N - 1; i >= 0; --i) {
        // 현재 탑보다 낮은 탑은 스택에서 제거하면서 answer 업데이트
        while (!cacheStack.empty() && heights[i] >= heights[cacheStack.top()]) {
            answer[cacheStack.top()] = i + 1;
            cacheStack.pop();
        }
        // 현재 탑의 인덱스를 스택에 추가
        cacheStack.push(i);
    }

    // 캐시 스택에 남은 값들은 왼쪽에 더 큰 탑이 없으므로 0 처리
    while (!cacheStack.empty()) {
        answer[cacheStack.top()] = 0;
        cacheStack.pop();
    }

    // 결과를 출력
    for (int i = 0; i < N; ++i) {
        cout << answer[i] << ' ';
    }

    return 0;
}
