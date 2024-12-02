// No. 1918: 후위 표기식 / Gold II
// https://www.acmicpc.net/problem/1918
#include <iostream>
#include <stack>

using namespace std;

int main(){
	string express;
	stack<char> st;
	cin >> express;
	for(const auto& p : express) { // string 객체의 문자열을 하나 하나 탐색
		if(p >= 'A' && p <= 'Z') {
			cout << p;
			continue;
		}
		if(st.empty()) {
			st.push(p);
			continue;
		}

		if (p == '(') {
			st.push(p);
		} else if (p == ')') { 
			while(!st.empty() && st.top() != '(') {
				cout << st.top();
				st.pop();
			}
			st.pop(); // stack에 남은 ( 문자도 제거
		} else if (p == '*' || p == '/') {
			while(!st.empty() && (st.top() == '*' || st.top() == '/')) {
				cout << st.top();
				st.pop();
			}
			st.push(p);
		} else if (p == '+' || p == '-') { 
			// *, / 이 있을 때 계속 pop, +, - 가 있어도 먼저 들어온 걸 pop  
			// 따라서 ( 가 아닐 때 계속 pop하도록 간단하게 수정
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