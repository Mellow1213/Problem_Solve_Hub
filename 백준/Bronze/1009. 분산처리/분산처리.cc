#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    while(T--) {
        int a, b;
        cin >> a >> b;

        a %= 10; // 끝자리만 보면 됨

        if(a == 0) {
            cout << 10 << '\n'; // 10의 배수는 10번째 컴퓨터
            continue;
        }

        int cycle[4];
        cycle[0] = a;
        for(int i = 1; i < 4; i++) {
            cycle[i] = (cycle[i-1] * a) % 10;
        }

        if(b % 4 == 0)
            cout << cycle[3] << '\n';
        else
            cout << cycle[(b % 4) - 1] << '\n';
    }
}
