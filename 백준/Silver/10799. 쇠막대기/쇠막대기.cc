#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string stick;
    cin >> stick;
    
    stack<int> s;
    int count = 0;
    
    for (int i = 0; i < stick.length(); i++) {
        if(stick[i]=='('){
            s.push('(');
        }
        else{
            s.pop();
            if(stick[i-1] == '('){ // 레이저
                count += s.size();
            }
            else{
                count++;
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}