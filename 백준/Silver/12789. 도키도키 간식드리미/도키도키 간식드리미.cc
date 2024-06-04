#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    stack<int> s;
    int currentN = 1;
    bool flag = true;
    
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        
        if(temp == currentN){
            currentN++;
        }
        else{
            s.push(temp);
        }
        while(!s.empty()){
        if(s.top() == currentN){
            currentN++;
            s.pop();
            continue;
        }
        break;
    }
    }
    
    cout << (s.empty() ? "Nice" : "Sad");
}
