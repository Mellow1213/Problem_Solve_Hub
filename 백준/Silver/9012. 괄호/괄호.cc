#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        string temp;
        cin >> temp;
        stack<char> stack;
            
            for(int i=0; i<temp.length(); i++){
                
                if(stack.empty()){
                    stack.push(temp[i]);
                }
                else{
                    if(temp[i] == '(')
                        stack.push(temp[i]);
                    else if(temp[i] == ')' && stack.top() == '(')
                        stack.pop();
                }
            }
                
        cout << (stack.empty() ? "YES" : "NO") << '\n';
    }
}