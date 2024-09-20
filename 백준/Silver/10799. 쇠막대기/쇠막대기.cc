#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string stick;
    cin >> stick;
    
    int stack_size = 0;
    int count = 0;
    int len = stick.length();
    
    for (int i = 0; i < len; i++) {
        if (stick[i] == '(') {
            stack_size++;
        }
        else {
            stack_size--;
            if (stick[i-1] == '(') { // 레이저
                count += stack_size;
            }
            else {
                count++;
            }
        }
    }
    
    cout << count << '\n';
    
    return 0;
}