#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    vector<int> arr;
    vector<vector<int>> DP_Great;
    vector<vector<int>> DP_Less;
    cin >> N;
    arr.assign(N+1, 0);
    DP_Great.assign(2, vector<int>(3));
    DP_Less.assign(2, vector<int>(3));
    
    for(int i=1; i<=N; i++){
        for(int j=0; j<3; j++)
            cin >> arr[j];
        DP_Great[1][0] = arr[0] + max(DP_Great[0][0], DP_Great[0][1]);
        DP_Great[1][1] = arr[1] + max(max(DP_Great[0][0], DP_Great[0][1]), DP_Great[0][2]);
        DP_Great[1][2] = arr[2] + max(DP_Great[0][1], DP_Great[0][2]);
        DP_Great[0][0] = DP_Great[1][0];
        DP_Great[0][1] = DP_Great[1][1];
        DP_Great[0][2] = DP_Great[1][2];
        
        DP_Less[1][0] = arr[0] + min(DP_Less[0][0], DP_Less[0][1]);
        DP_Less[1][1] = arr[1] + min(min(DP_Less[0][0], DP_Less[0][1]), DP_Less[0][2]);
        DP_Less[1][2] = arr[2] + min(DP_Less[0][1], DP_Less[0][2]);
        DP_Less[0][0] = DP_Less[1][0];
        DP_Less[0][1] = DP_Less[1][1];
        DP_Less[0][2] = DP_Less[1][2];
    }
    
    int great = -1;
    int min = 9999999;
    for(int i=0; i<3; i++){
        if(great < DP_Great[1][i])
            great = DP_Great[1][i];
        if(min > DP_Less[1][i])
            min = DP_Less[1][i];
    }
    
    cout << great << ' ' << min;
    
}