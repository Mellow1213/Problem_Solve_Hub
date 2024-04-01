#include <iostream>
#include <map>

using namespace std;

int main()
{   
    ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    map<int, int> numHash;
    int N;
    cin >> N;
    int arrN[N];
    
    for(int i=0; i<N; i++){
        cin >> arrN[i];
        if(numHash.find(arrN[i]) == numHash.end())
            numHash.insert(pair<int, int>(arrN[i], 1));
        else
            numHash[arrN[i]] += 1;
    }
    
    int M;
    cin >> M;
    int arrM[M];
    
    for(int i=0; i<M; i++){
        cin >> arrM[i];
        cout << numHash[arrM[i]] << ' ';
    }
}