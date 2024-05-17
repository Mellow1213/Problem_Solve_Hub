#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    priority_queue<int, vector<int>> q;
    int testCase;
    
    cin >> testCase;
    
    for(int t=0; t<testCase; t++){
        int temp;
        cin >> temp;
        
        if(temp == 0){
            if(q.empty())
                cout << 0 << '\n'; // 줄 바꿈 추가
            else{
                cout << q.top() << '\n';
                q.pop();
            }
            continue;
        }
        
        q.push(temp);
    }
}
