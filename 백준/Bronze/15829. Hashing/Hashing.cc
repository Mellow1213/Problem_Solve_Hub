#include <iostream>
#include <vector>
using namespace std;

int M = 1234567891;

long long int paw(int num, int cnt){
    long long int answer = 1;
    for(int i=1; i<=cnt; i++){
        answer = (answer*num) % M;
    }
    return answer%M;
}

long long int Hash(vector<char> v){
    long long int answer = 0;
    
    for(int i=0; i<v.size(); i++){
        long long int hash = ((int)v[i]-96)*paw(31, i)%M;
        answer =(answer + hash)%M;
    }
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int L;
    vector<char> v;
    cin >> L;
    
    for(int i=0; i<L; i++){
        char temp;
        cin >> temp;
        v.push_back(temp);
    }
    cout << Hash(v);
}
