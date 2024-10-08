#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> arr;
vector<int> inbox;
vector<bool> visit;

void Trace(int depth){
    if(depth == M){
        for(const auto& p : inbox)
            cout << p << ' ';
        cout << '\n';
        return;
    }
    
    for(int i=0; i<N; i++){
        if(!visit[i]){
            inbox[depth] = arr[i];
            visit[i] = true;
            Trace(depth+1);
            visit[i] = false;
        }
        
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    arr.resize(N);
    inbox.resize(M);
    visit.assign(N, false);
    
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    Trace(0);
}