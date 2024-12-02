// No. 1918: 후위 표기식 / Gold II
// https://www.acmicpc.net/problem/1918
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string _express;
    stack<char> st;
    cin >> _express;
    for (const auto &p : _express)
    {
        if(p >= 'A' && p <= 'Z') {
            cout << p;
            continue;
        }

        if(st.empty()) {
            st.push(p);
            continue;
        }

        if(p == '(') {
            st.push(p);
        } 
        else if (p == ')') {
            while(!st.empty() && st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.pop();
        }
        else if (p == '*' || p == '/') {
            while(!st.empty() && (st.top() == '*' || st.top() == '/')) {
                cout << st.top();
                st.pop();
            }
            st.push(p);
        }
        else if(p == '-' || p == '+') {
            while(!st.empty() && st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.push(p);
        }
    }

    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
}