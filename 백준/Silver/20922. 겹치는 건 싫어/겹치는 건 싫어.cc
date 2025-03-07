#include <iostream>
#include <vector>
#include <unordered_map>

#define FastIO ios_base::sync_with_stdio(false);  cin.tie(0); cout.tie(0);
using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int main()
{
    FastIO;
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    unordered_map<int, int> m;
    int left = 0, right = 0;
    int size = -1;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    while (right < N) {
        int curNum = arr[right];
        m[curNum]++;
        
        // 만약 K를 초과했다면 left를 이동하면서 조건을 만족하도록 만든다.
        while (m[curNum] > K) {
            m[arr[left]]--;
            left++;
        }

        // 부분 수열 크기 갱신
        size = max(size, right - left + 1);

        right++;
    }
    
    cout << size;
}
