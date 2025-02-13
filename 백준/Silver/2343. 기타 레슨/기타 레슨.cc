#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    
    vector<int> lecture(N);
    
    int left = 0;
    int right = 0;
    
    for(int i=0; i<N; i++) {
        cin >> lecture[i];
        
        if(left < lecture[i]) 
            left = lecture[i];
        right += lecture[i];
    }
    
    while(left <= right) {
        int mid = (left + right) / 2;
        int cnt = 0;
        int sum = 0;
        for(int i=0; i<N; i++) {
            if(sum + lecture[i] > mid) {
                sum = 0;
                cnt++;
            }
            sum += lecture[i];
        }
        if(sum != 0)    cnt++;
        
        if(cnt > M) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << left;
}