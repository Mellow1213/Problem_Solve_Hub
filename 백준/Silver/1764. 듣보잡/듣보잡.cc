#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    map<string, int> m;
    int N, M, cnt = 0;
    
    cin >> N >> M;
    
    for(int i=0; i<N+M; i++){
        string temp;
        cin >> temp;
        m[temp]++;
        if(m[temp] == 2)
            cnt++;
    }
    
    cout << cnt << '\n';
    
    for(auto iter = m.begin(); iter != m.end(); iter++){
        if(iter->second==2)
            cout << iter->first << '\n';
    }
}
