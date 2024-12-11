#include <iostream>
typedef long long ll_t;
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    
    ll_t high = (ll_t)N * N;
    ll_t low = 1;
    
    while (low < high) {
        ll_t mid = (high + low) / 2;
        ll_t cnt = 0; // cnt를 long long 타입으로 변경
        
        for (int i = 1; i <= N; i++) {
            cnt += min((ll_t)N, mid / i); // 잘못된 연산 수정
        }
        
        if (cnt < K) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    cout << high;
    return 0;
}
