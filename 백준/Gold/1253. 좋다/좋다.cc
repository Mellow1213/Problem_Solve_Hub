#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    int good = 0;
    for(int i=0; i<N; i++) {
        int left = 0;
        int right = N-1;
        
        while(left < right) {
            if(left == i) {
                left++; continue;
            }
            if(right == i) {
                right--; continue;
            }
            int temp = arr[left] + arr[right];
            if(temp == arr[i]) {
                good++;
                break;
            }
            else if(temp < arr[i]) {
                left++;
            }
            else{
                right--;
            }
        }
    }
    cout << good;
}