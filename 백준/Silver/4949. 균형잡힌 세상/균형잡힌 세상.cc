#include <iostream>
#include <vector>

using namespace std;

class Stack{
    private:
        vector<char> v;
        int pointer = -1;
    public:
        void Push(char ch){
            v.push_back(ch);
            pointer++;
        }
        char Pop(){
            if (!IsEmpty()) {
                char ch = v[pointer];
                v.erase(v.begin() + pointer);
                pointer--;
                return ch;
            }
            return '\0';  // Empty stack 경우 처리
        }
        bool IsEmpty(){
            return pointer <= -1;
        }
        void Clear(){
            v.clear();
            pointer = -1;
        }
};

bool IsEquaility(char ch1, char ch2){
    if(ch1 == '(' && ch2 == ')')
        return true;
    else if (ch1 == '[' && ch2 == ']')
        return true;
    return false;
}

int main() {
    Stack s;
    string str;
    bool flag;

    while (true) {
        getline(cin, str, '.');
        if (cin.peek() == '\n' || cin.peek() == EOF) {
            cin.get();  // Consume the newline character or EOF
            if (str.empty()) break;
        }

        flag = true;
        s.Clear();  // Make sure the stack is clear for new input

        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '[' || str[i] == '(') {
                s.Push(str[i]);
                continue;
            }

            if (str[i] == ']' || str[i] == ')') {
                if (s.IsEmpty() || !IsEquaility(s.Pop(), str[i])) {
                    flag = false;
                    break;
                }
            }
        }

        if (!s.IsEmpty()) flag = false; // If stack is not empty, mismatch found

        cout << (flag ? "yes" : "no") << '\n';
    }
}
