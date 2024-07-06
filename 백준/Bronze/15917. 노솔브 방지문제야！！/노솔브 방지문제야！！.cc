#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Q;

    cin >> Q;

    for(int i = 0; i < Q; i++){
        int a;
        cin >> a;
        cout << (((a & (-a)) == a) ? 1 : 0) << '\n';
    }

    return 0;
}
