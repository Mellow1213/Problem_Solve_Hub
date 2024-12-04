#include <iostream>
#include <vector>
#include <deque>
#include <stack>

using namespace std;

typedef pair<char, int> CH;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string str, exp_str;
    deque<CH> st;

    cin >> str >> exp_str;

    int counter = 0;
    const int COUNT_MAX = exp_str.length();

    for(const auto& p : str) {
        if(p==exp_str[counter]) {
            counter++;
        }
        else {
            counter = exp_str[0] == p ? 1 : 0;
        }

        if(counter == COUNT_MAX) {
            for(int i=0; i<COUNT_MAX-1; i++) { // 마지막 문자를 push하지 않아서 MAX-1 사용
                st.pop_back();
            }
            
            counter = st.empty() ? 0 : st.back().second;
            continue;
        }
        
        st.push_back({p, counter});
    }

    if(st.empty()) {
        cout << "FRULA";
    } else
    while(!st.empty()) {
        cout << st.front().first;
        st.pop_front();
    }
}