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

void LCD::drawSegment(int x, int y, int segment, int size) { // 세그먼트 그리기
    switch (segment) {
        case 0: for(int i=1; i<=size; i++)   canvas[y][x+i]                 = '-'; break;
        case 1: for(int i=1; i<=size; i++)   canvas[y+i][x]                 = '|'; break;
        case 2: for(int i=1; i<=size; i++)   canvas[y+i][x+size+1]          = '|'; break;
        case 3: for(int i=1; i<=size; i++)   canvas[y+size+1][x+i]          = '-'; break;
        case 4: for(int i=1; i<=size; i++)   canvas[y+size+1+i][x]          = '|';break;
        case 5: for(int i=1; i<=size; i++)   canvas[y+size+1+i][x+size+1]   = '|'; break;
        case 6: for(int i=1; i<=size; i++)   canvas[y+2*(size+1)][x+i]      = '-'; break;
    }
}

void LCD::draw() { // 숫자 그리기
    int xOffset = 0;
    for(const auto& p : displayNum) {
        int currentNum = p - '0';
        for(int i=0; i<7; i++) {
            if(SEGMENT_MAP[currentNum][i]) {
                drawSegment(xOffset, 0, i, pixSize);
            }
        }
        xOffset+=pixSize+3;
    }
    printCanvas();
}

void LCD::printCanvas() { // 캔버스의 숫자 출력
    for(const auto& p : canvas) {
        for(const auto& q : p) {
            cout << q;
        }
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
