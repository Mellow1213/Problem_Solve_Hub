#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, x;
    cin >> n;
    vector<int> arr(n);
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cin >> x;
    
    sort(arr.begin(), arr.end());
    
    int leftPtr = 0;
    int rightPtr = n-1;
    int cnt = 0;
    while(rightPtr > leftPtr){
        if(arr[rightPtr] + arr[leftPtr] == x){
            cnt++;
            leftPtr++;
        }
        else if(arr[rightPtr] + arr[leftPtr] > x){
            rightPtr--;
        }
        else{
            leftPtr++;
        }
    }
    cout << cnt;
}