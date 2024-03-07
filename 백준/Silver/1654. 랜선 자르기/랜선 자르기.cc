#include <iostream>
#include <vector>

using namespace std;
int main() {
    int haveLanCnt;
    int needLanCnt;
    long long high = 0, mid = 0;
    long long low = 1;
    long long answer = 0;

    cin >> haveLanCnt >> needLanCnt;

    vector<long long> lanVector(haveLanCnt);

    for(int i = 0; i < haveLanCnt; i++) {
        cin >> lanVector[i];
        high = max(high, lanVector[i]);
    }

    while(low <= high) {
        mid = (high + low) / 2;
        int count = 0;

        for(int i = 0; i < haveLanCnt; i++) {
            count += lanVector[i] / mid;
        }

        if(count < needLanCnt) {
            high = mid - 1;
        } else {
            low = mid + 1;
            answer = max(answer, mid);
        }
    }

    cout << answer << endl;

    return 0;
}
