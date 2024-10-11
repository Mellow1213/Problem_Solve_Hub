#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> dataset;
vector<int> selection;

void BackTrack(int depth, int lastidx){
    if(depth >= M){
        for(const auto& p : selection){
            cout << p << ' ';
        }
        cout << '\n';
        return;
    }
    
    int prev = 0;
    for(int i=lastidx; i<N; i++){
        if(dataset[i] != prev){
            prev = dataset[i];
            selection[depth] = dataset[i];
            BackTrack(depth+1, i);
        }
    }
}

int main()
{
    cin >> N >> M;
    
    dataset.resize(N);
    selection.resize(M);
    
    for(int i=0; i<N; i++){
        cin >> dataset[i];
    }
    
    sort(dataset.begin(), dataset.end());
    
    BackTrack(0, 0);
}