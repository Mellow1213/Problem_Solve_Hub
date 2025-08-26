#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N, S;

int min(int a, int b) { return a<b?a:b; }

int Shortest(vector<int>& arr) {
    int left = 0, right = 0;
    int curSum = 0;
    int minLength = INT_MAX;
    
    while(true) {
        if(curSum >= S) {
            minLength = min(minLength, right-left);
            curSum -= arr[left];
            left++;
        } else {
            if(right == N) break;
            curSum += arr[right];
            right++;
        }
    }
    return (minLength == INT_MAX ? 0 : minLength);
}

int main()
{
    cin >> N >> S;
    vector<int> arr(N);
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    
    cout << Shortest(arr);
}