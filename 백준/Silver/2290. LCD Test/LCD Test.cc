#include <iostream>
#include <vector>

using namespace std;

// 7-Segment 데이터
const int SEGMENT_MAP[10][7] = {
    {1, 1, 1, 0, 1, 1, 1}, // 0
    {0, 0, 1, 0, 0, 1, 0}, // 1
    {1, 0, 1, 1, 1, 0, 1}, // 2
    {1, 0, 1, 1, 0, 1, 1}, // 3
    {0, 1, 1, 1, 0, 1, 0}, // 4
    {1, 1, 0, 1, 0, 1, 1}, // 5
    {1, 1, 0, 1, 1, 1, 1}, // 6
    {1, 0, 1, 0, 0, 1, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}  // 9
};

class LCD {
private:
    vector<vector<char>> canvas;
    int pixSize;
    int pixWidth;
    int pixHeight;
    string displayNum;

    void drawSegment(int x, int y, int segment, int size);
    void printCanvas();

public:
    LCD(string num, int size) : pixSize(size), displayNum(num) {
        pixWidth = num.size() * (size + 3) - 1;
        pixHeight = 2 * size + 3;
        canvas.assign(pixHeight, vector<char>(pixWidth, ' '));
    }

    void draw();
};

void LCD::drawSegment(int x, int y, int segment, int size) {
    switch (segment) {
        case 0: // 상단 가로
            for (int i = 1; i <= size; i++) canvas[y][x + i] = '-';
            break;
        case 1: // 좌상단 세로
            for (int i = 1; i <= size; i++) canvas[y + i][x] = '|';
            break;
        case 2: // 우상단 세로
            for (int i = 1; i <= size; i++) canvas[y + i][x + size + 1] = '|';
            break;
        case 3: // 중앙 가로
            for (int i = 1; i <= size; i++) canvas[y + size + 1][x + i] = '-';
            break;
        case 4: // 좌하단 세로
            for (int i = 1; i <= size; i++) canvas[y + size + 1 + i][x] = '|';
            break;
        case 5: // 우하단 세로
            for (int i = 1; i <= size; i++) canvas[y + size + 1 + i][x + size + 1] = '|';
            break;
        case 6: // 하단 가로
            for (int i = 1; i <= size; i++) canvas[y + 2 * size + 2][x + i] = '-';
            break;
    }
}

void LCD::draw() {
    int xOffset = 0;
    for (char c : displayNum) {
        int digit = c - '0';
        for (int seg = 0; seg < 7; seg++) {
            if (SEGMENT_MAP[digit][seg]) {
                drawSegment(xOffset, 0, seg, pixSize);
            }
        }
        xOffset += pixSize + 3; // 숫자 간격 조정
    }
    printCanvas();
}

void LCD::printCanvas() {
    for (auto &row : canvas) {
        for (char c : row) cout << c;
        cout << '\n';
    }
}

int main() {
    int s;
    string n;
    cin >> s >> n;

    LCD lcd(n, s);
    lcd.draw();

    return 0;
}
