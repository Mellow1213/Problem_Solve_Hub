#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Homework {
    int t, d;
};

bool cmp(const Homework& a, const Homework& b) {
    return a.d > b.d; // 마감일이 늦은 순서대로
}

int main() {
    int N;
    cin >> N;
    vector<Homework> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i].t >> arr[i].d;
    }

    sort(arr.begin(), arr.end(), cmp);

    int day = arr[0].d;
    for (int i = 0; i < N; i++) {
        day = min(day, arr[i].d);
        day -= arr[i].t;
    }

    cout << day << '\n';
    return 0;
}
