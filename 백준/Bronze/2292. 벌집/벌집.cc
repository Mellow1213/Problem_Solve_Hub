#include<iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int layer = 0; // 시작하는 레이어는 0
    int max_room_number = 1; // 각 레이어의 최대 방 번호

    while (max_room_number < N) {
        layer++; // 레이어를 하나 증가
        max_room_number += layer * 6; // 각 레이어의 최대 방 번호 계산
    }

    cout << layer + 1 << endl; // 결과 출력 (레이어는 1부터 시작)

    return 0;
}
