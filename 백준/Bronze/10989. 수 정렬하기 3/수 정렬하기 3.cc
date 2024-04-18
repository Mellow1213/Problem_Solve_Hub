#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int testCase;
    int arr[10001] = { 0,};
    cin >> testCase;
    
    for(int i=0; i<testCase; i++){
        int temp;
        cin >> temp;
        arr[temp]++;
    }
    for(int i=0; i<10001; i++){
        if(arr[i] == 0) continue;
        
        for(int j=0; j<arr[i]; j++)
            cout << i << '\n';
    }
}
