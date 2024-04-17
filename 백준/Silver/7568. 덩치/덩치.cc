#include <iostream>

using namespace std;

int CalculateDung(pair<int, int> a, pair<int, int> b){
    if(a.first < b.first && a.second < b.second)
        return 1;
    else
        return 0;
    
}

int main()
{
    int n;
    cin >> n;
    
    pair<int, int> data[n];
    int rank[n] = {0,};
    
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        data[i] = make_pair(a, b);
    }
    
    for(int i=0; i<n; i++){
        int currentSum = 1;
        for(int j=0; j<n; j++){
            if(i == j) continue;
            currentSum += CalculateDung(data[i], data[j]);
        }
        cout << currentSum << ' ';
    }
}