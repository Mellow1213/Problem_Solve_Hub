#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    vector<int> vec;
    unordered_map<int, int> m;
    
    cin >> N;
    vec.assign(N, -1);
    
    int p1 = 0;
    int size = -1;
    
    for(int i=0; i<N; i++){
        cin >> vec[i];
        m[vec[i]]++;
        
        while(m.size()>2){
            m[vec[p1]]--;
            if(m[vec[p1]] == 0){
                m.erase(vec[p1]);
            }
            p1++;
        }
        
        size = max(size, i-p1+1);
    }
    
    cout << size;
}