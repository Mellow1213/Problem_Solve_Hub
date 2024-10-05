#include <iostream>

using namespace std;

int main() {
    int A, B;
    
    // 입력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // EOF까지 입력 받기
    while (cin >> A >> B) {
        cout << A + B << '\n';
    }
    
    return 0;
}