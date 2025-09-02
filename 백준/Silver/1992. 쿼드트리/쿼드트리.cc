#include <bits/stdc++.h>
using namespace std;

class Compresser {
private:
    vector<vector<char>> _origin;
    int _size;

    void InitOrigin() {
        _origin.assign(_size, vector<char>(_size));
        for (int i = 0; i < _size; ++i) {
            string row; cin >> row;
            for (int j = 0; j < _size; ++j) {
                _origin[i][j] = row[j];
            }
        }
    }

    bool IsFull(int x, int y, int size) {
        char first = _origin[y][x];
        for (int i = y; i < y + size; ++i) {
            for (int j = x; j < x + size; ++j) {
                if (_origin[i][j] != first) return false;
            }
        }
        return true;
    }

public:
    Compresser(int size) : _size(size) {
        InitOrigin();
    }

    void DebugShow() {
        cout << "--------------Debug---------------\n";
        for (const auto& row : _origin) {
            for (const auto& c : row) cout << c;
            cout << '\n';
        }
    }

    // 기준점 (x,y), 정사각형 한 변 길이 size
    void Compress(int x, int y, int size) {
        if (IsFull(x, y, size)) {
            cout << _origin[y][x];
            return;
        }
        cout << '(';
        int h = size / 2;
        // 쿼드트리 출력 순서: 왼위, 오위, 왼아래, 오아래
        Compress(x,       y,       h); // LU
        Compress(x + h,   y,       h); // RU
        Compress(x,       y + h,   h); // LD
        Compress(x + h,   y + h,   h); // RD
        cout << ')';
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    cin >> N;
    Compresser comp(N);
    // comp.DebugShow(); // 필요하면 켜기
    comp.Compress(0, 0, N);
    return 0;
}
