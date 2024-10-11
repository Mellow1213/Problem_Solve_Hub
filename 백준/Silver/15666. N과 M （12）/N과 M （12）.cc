#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> dataset;
vector<int> selection;

void BackTrack(int depth){
    if(depth >= M){
        for(const auto& p : selection){
            cout << p << ' ';
        }
        cout << '\n';
        return;
    }
    
    int prev = 0;
    for(int i=0; i<N; i++){
        if(dataset[i] != prev){
            if(depth != 0)
                if(selection[depth-1] > dataset[i])
                    continue;
            prev = dataset[i];
            selection[depth] = dataset[i];
            BackTrack(depth+1);
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
    
    BackTrack(0);
}