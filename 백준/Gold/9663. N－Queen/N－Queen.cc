#include <iostream>
#include <vector>
using namespace std;

int N;
int answer = 0;
vector<bool> col, diag1, diag2; // 열, 대각선1, 대각선2 체크용 배열

void BackTrack(int row) {
    if (row == N) { // N행까지 퀸을 배치했다면 탐색 끝
        answer++;
        return;
    }

    for (int c = 0; c < N; c++) {
        if (col[c] || diag1[row + c] || diag2[row - c + N - 1]) continue;

        // 현재 위치에 퀸 배치
        col[c] = diag1[row + c] = diag2[row - c + N - 1] = true;
        BackTrack(row + 1);
        // 퀸 제거
        col[c] = diag1[row + c] = diag2[row - c + N - 1] = false;
    }
}

int main() {
    cin >> N;

    col.assign(N, false);
    diag1.assign(2 * N - 1, false);
    diag2.assign(2 * N - 1, false);

    BackTrack(0); // 0행부터 백트래킹 시작

    cout << answer;
    return 0;
}
