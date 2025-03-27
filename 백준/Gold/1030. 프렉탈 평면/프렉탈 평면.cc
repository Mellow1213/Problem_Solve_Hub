#include <iostream>
using namespace std;
int s, n, k, r1, r2, c1, c2;

int func(int len, int x, int y) {
    if(len == 1) return 0;
    int new_len = len / n; // 단위 시간 당 나눠진 한 변의 길이
    // 해당 영역이 검정색인지 확인. 
    // 해당 수식은 직접 좌표를 계산해보면 답이 나옴
    // new_len을 단위 길이로 잡고 n과 k의 비율 계산 후 검정 좌표 결정
    if(x >= new_len * (n-k)/2 && x < new_len * (n+k)/2
        && y >= new_len * (n-k)/2 && y < new_len * (n+k)/2) {
            return 1;
        }
    // 하얀색으로 판정된 좌표는 다른 영역과 독립적으로 패턴을 수행
    // 따라서 새 영역이 어디 위치해있는지는 나누기 연산
    // 그리고 그 연산의 나머지가 새 영역에서의 위치. 
    return func(new_len, x % new_len, y % new_len);
}

int main()
{
    cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;
    
    int len = 1;
    while(s--) len *= n; // 한 변의 길이는 N^s
    
    // 영역의 모든 점에서 수행.
    // O(N^2), 
    for(int i=r1; i<=r2; i++) {
        for(int j=c1; j<=c2; j++) {
            cout << func(len, i, j);
        }
        cout << '\n';
    }
}