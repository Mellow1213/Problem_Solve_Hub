#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    char make[5] = {'M', 'O', 'B', 'I', 'S'};
    unordered_set<char> s;
    string arr;
    cin >> arr;
    for(int i=0; i<arr.size(); i++){
        s.insert(arr[i]);        
    }
    for(int i=0; i<5; i++){
        if(s.find(make[i]) == s.end()){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}