#include <iostream>
#define ll long long
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll T, N;
    cin >> T;
    while (T--)
    {
        cin >> N;
        N--; N %= 28; N++;
        if (16 <= N) N = 30 - N;

        for (ll i = 8; i >= 1; i /= 2)
        {
            if (N >= i)
            {
                cout << "딸기";
                N -= i;
            }
            else cout << "V";
        }
        cout << "\n";
    }
}