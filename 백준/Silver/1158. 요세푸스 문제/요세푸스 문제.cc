#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int N, K;
    vector<int> vec;
    queue<int> q;
    cin >> N >> K;
    
    for(int i=1; i<=N; i++){
        vec.push_back(i);
    }
    
    int erasePtr = 0;
    while(!vec.empty()){
        erasePtr = (erasePtr + K - 1) % vec.size();
        q.push(vec[erasePtr]);
        vec.erase(vec.begin() + erasePtr);
    }
    
    cout << "<";
    for(int i=0; i<N; i++){
        cout << q.front();
        q.pop();
        if(i < N-1) cout << ", ";
    }
    cout << ">";
}