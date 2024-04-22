#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> v;
    int N, K;
    int cnt = 0;
    
    cin >> N >> K;
    
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    
    while(K != 0){
        
        for(int i=v.size()-1; i>=0; i--){
            int temp = K % v[i];
            
            if(temp != K){
                cnt += K / v[i];
                K = temp;
            }
            
        }
        
    }
    
    cout << cnt;
}
