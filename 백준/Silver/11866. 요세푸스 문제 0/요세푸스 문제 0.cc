#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int numberOfPeople;
    int targetJumpLength;
    
    queue<int> currentQueue;
    
    cin >> numberOfPeople >> targetJumpLength;
    
    for(int i=1; i<=numberOfPeople; i++){
        currentQueue.push(i);
    }
    
    
    cout << '<';
    while(!currentQueue.empty()){
        for(int i=0; i<targetJumpLength-1; i++){
            currentQueue.push(currentQueue.front());
            currentQueue.pop();
        }
        cout << currentQueue.front();
        if(currentQueue.size() > 1)  cout<<", ";
        currentQueue.pop();
    }
    cout << '>';
}
