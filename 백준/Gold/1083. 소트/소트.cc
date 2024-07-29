#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, S;
    vector<int> vec;
    cin >> N;
    vec.resize(N);
    for(int i=0; i<N; i++){
        cin >> vec[i];
    }
    cin >> S;
    
    int targetIdx = 0;
    while(S>0 && targetIdx<N){
        int maxElement = vec[targetIdx];
        int index = targetIdx;
        int findRange = min(targetIdx+S, N-1);
        
        for(int i=targetIdx+1; i<=findRange; i++){
            if(maxElement < vec[i]){
                maxElement = vec[i];
                index = i;
            }
        }
    
        for(int i=index; i>targetIdx; i--){
            swap(vec[i], vec[i-1]);
        }
        
        S -= index - targetIdx;
        targetIdx++;
    }
    
    for(const auto& p : vec){
        cout << p << ' ';
    }

    return 0;
}