#include <iostream>
#include <queue>

using namespace std;


int main()
{
    int N;
    
    queue<int> q;
    
    cin >> N;
    
    int arr[N];
    
    for(int i=1; i<N+1; i++){
        q.push(i);
    }
    
    while(q.size()>1){
        q.pop();
        q.push(q.front());
        q.pop();
        
    }
    
    cout << q.front();
}
