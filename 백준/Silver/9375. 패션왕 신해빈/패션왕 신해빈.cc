#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int testCase;
    
    cin >> testCase;
    
    for(int i=0; i<testCase; i++){
        int clothes;
        cin >> clothes;
        unordered_map<string, int> map;
        
        for(int j=0; j<clothes; j++){
            string name, tag;
            cin >> name >> tag;
            map[tag]++;
        }
        
        int answer=1;
    
        for(auto iter : map){
            answer *= (iter.second+1);
        }
        cout << --answer << '\n';
    }
}
