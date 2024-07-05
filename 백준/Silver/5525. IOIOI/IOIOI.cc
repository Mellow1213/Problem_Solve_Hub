#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    string str;
    int cnt = 0;
    int k=0;
    
    cin >> N >> M;
    cin >> str;
    
    for(int i=0; i<M; i++){
        if(str[i] == 'O'){
            continue;
        }
        
        while(str[i+1] == 'O' && str[i+2] == 'I'){
            k++;
            if(k >= N){
                cnt++;
            }
            i+=2;
        }
        k=0;
    }
    
    
    cout << cnt;
}