#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int H, W, N, M;
    cin >> H >> W >> N >> M;
    cout << ((H - 1) / (N + 1) +1) * ((W - 1) / (M + 1) +1);
    return 0;
}
