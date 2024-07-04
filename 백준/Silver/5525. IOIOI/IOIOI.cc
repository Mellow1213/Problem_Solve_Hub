#include <iostream>
#include <string>
using namespace std;

string InitStr(int n){
    string str = "I";
    
    for(int i=0; i<n; i++){
        str.push_back('O');
        str.push_back('I');
    }
    
    return str;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    string str;
    int cnt = 0;
    
    cin >> N >> M;
    cin >> str;
    
    const string targetStr = InitStr(N);
    
    for(int i=0; i<str.size(); i++){
        if(str[i] == 'I'){
            string curStr = str.substr(i, targetStr.size());
            if(curStr.compare(targetStr) == 0)
                cnt++;
        }
    }
    
    
    cout << cnt;
}