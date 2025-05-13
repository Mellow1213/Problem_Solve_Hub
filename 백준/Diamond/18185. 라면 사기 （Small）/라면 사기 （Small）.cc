#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> arr(N + 2);  // out-of-bound 방지용 +2

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < N; i++) {
        // Case 1: arr[i+1] > arr[i+2]일 경우, 3개 묶음 전에 2개 묶음을 먼저 처리
        if (arr[i + 1] > arr[i + 2]) {
            int two = min(arr[i], arr[i + 1] - arr[i + 2]);
            arr[i] -= two;
            arr[i + 1] -= two;
            sum += 5 * two;
        }

        // Case 2: 3개 묶음을 가능한 만큼 처리
        int three = min({arr[i], arr[i + 1], arr[i + 2]});
        arr[i] -= three;
        arr[i + 1] -= three;
        arr[i + 2] -= three;
        sum += 7 * three;

        // Case 3: 남은 건 2개 묶음
        int two = min(arr[i], arr[i + 1]);
        arr[i] -= two;
        arr[i + 1] -= two;
        sum += 5 * two;

        // Case 4: 나머지는 1개씩 처리
        sum += 3 * arr[i];
        arr[i] = 0;
    }

    cout << sum;
    return 0;
}
