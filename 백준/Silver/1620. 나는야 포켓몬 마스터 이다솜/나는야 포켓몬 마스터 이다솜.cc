#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool IsDigit(string str){
    return atoi(str.c_str()) != 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    unordered_map<string, int> map;
    vector<string> vec;
    int N, M;
    
    cin >> N >> M;
    
    vec.resize(N+1);
    
    for(int i=1; i<=N; i++){
        string temp;
        cin >> temp;
        map.insert(make_pair(temp, i));
        vec[i] = temp;
    }
    
    for(int i=0; i<M; i++){
        string temp;
        cin >> temp;
        if(IsDigit(temp)){
            cout << vec[atoi(temp.c_str())] << '\n';
        }
        else{
            cout << map.find(temp)->second << '\n';
        }
    }
}
