#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T>0){
        int L;
        cin >> L;
        // 수업시간이 L이면 늦은 시간 s + 빨리 끝내주는 시간 t
        // L = s + t
        // s = t^2 이므로
        // L = t^2 + t
        // 지각 시간을 구하므로 편하게 t로 치환하자.
        // 그러면 t^2 + t < L 을 만족하는 최대의 정수를 구하면 되는거 아님?
        // 이차 부등식 t^2 + t - L < 0
        // 근의 공식 중 a = 1, b = 1, c = -L
        // t = { -1 + root(1 + 4L) } / 2
        cout << floor(( -1 + sqrt( 1 + 4*L )) / 2 ) << '\n';
        T--;
    }
}