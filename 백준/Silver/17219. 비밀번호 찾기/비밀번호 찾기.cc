#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    map<string, string> m;
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        string temp1, temp2;
        cin >> temp1 >> temp2;
        m[temp1] = temp2;
    }
    
    for(int i=0; i<M; i++){
        string temp;
        cin >> temp;
        cout << m[temp] << '\n';
    }
}