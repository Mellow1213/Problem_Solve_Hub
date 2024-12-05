#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<int> value(N);
    unordered_map<int, int> mp;
    vector<int> answer(N);
    stack<int> st;

    for(int i=0; i<N; i++) {
        int tmp;
        cin >> tmp;
        value[i] = tmp;
        mp[tmp]++;
    }

    for(int i=N-1; i>=0; i--) {
        while(!st.empty() && mp[st.top()] <= mp[value[i]]) {
            st.pop();
        }
        answer[i] = st.empty() ? -1 : st.top();
        st.push(value[i]);
    }

    for(const auto& p : answer) {
        cout << p << ' ';
    }
}