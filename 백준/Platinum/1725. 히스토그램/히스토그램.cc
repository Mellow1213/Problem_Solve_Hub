#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int N;
    cin >> N;
    long long MAX = 0;  // 결과가 int 범위를 넘을 수 있으므로 long long 사용
    stack<int> st;
    vector<int> sticks(N+2, 0);
    
    for(int i=1; i<=N; i++) {  // 인덱스를 1부터 시작
        cin >> sticks[i];
    }

    st.push(0);  // 시작 인덱스는 0 (높이가 0인 가상의 막대)
    for(int i=1; i<=N+1; i++) {
        while(!st.empty() && sticks[st.top()] > sticks[i]) {
            int height = sticks[st.top()];  // 높이 저장
            st.pop();
            long long width = i - st.top() - 1;  // 너비 계산
            MAX = max(MAX, height * width);  // 높이와 너비를 곱함
        }
        st.push(i);
    }
    
    cout << MAX;
    return 0;
}