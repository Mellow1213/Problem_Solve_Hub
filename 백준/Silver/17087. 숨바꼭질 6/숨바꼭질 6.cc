#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // GCD 함수

using namespace std;

int main() {
    int N, originPos;
    cin >> N >> originPos;
    vector<int> points(N);
    vector<int> dists(N);

    for(int i=0; i<N; i++) {
        cin >> points[i];
        dists[i] = abs(points[i] - originPos);
    }

    int result = dists[0];
    for(int i=1; i<N; i++) {
        result = gcd(result, dists[i]);
    }
    
    cout << result;
}