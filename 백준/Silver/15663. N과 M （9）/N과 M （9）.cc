#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dataSet;
vector<int> temp;
vector<bool> visit;

void Backtrack(int depth){
    if(depth >= temp.size()){
        for(const auto& p : temp){
            cout << p << ' ';
        }
        cout << '\n';
        return;
    }
    
    int tmp = 0;
    for(int i=0; i<dataSet.size(); i++){
        if(!visit[i] && tmp != dataSet[i]){
            temp[depth] = dataSet[i];
            tmp = dataSet[i];
            visit[i] = true;
            Backtrack(depth+1);
            visit[i] = false;
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    
    dataSet.resize(N);
    temp.resize(M);
    visit.assign(N, false);
    
    for(int i=0; i<N; i++){
        cin >> dataSet[i];
    }
    
    sort(dataSet.begin(), dataSet.end());
    
    Backtrack(0);
}