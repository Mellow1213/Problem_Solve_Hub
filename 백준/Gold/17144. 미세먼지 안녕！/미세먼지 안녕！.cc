#include <iostream>
#include <vector>

#define Field vector<vector<int>>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


using namespace std;

class Cleaner {
    Field field;
    int f_Row;
    int f_Column;
    bool isInitSize = false;
    vector<pair<int, int>> cleanPos;
    const int dirY[4] = {0, 0, 1, -1};
    const int dirX[4] = {1, -1, 0, 0};
    public:
        Cleaner(int R, int C) : f_Row(R), f_Column(C) {
            isInitSize = true;
            field.assign(f_Row, vector<int>(C));
        }
    
        void InitField() {
            if(!isInitSize) return;
            for(int i=0; i<f_Row; i++) {
                for(int j=0; j<f_Column; j++) {
                    cin >> field[i][j];
                    if(field[i][j] == -1) {
                        cleanPos.push_back({i, j});
                    }
                }
            }
        }
        
        void PrintMap() const {
            if(!isInitSize) return;
            cout << "\n======== Print Map (Debug) ========\n";
            for(int i=0; i<f_Row; i++) {
                for(int j=0; j<f_Column; j++) {
                    cout << field[i][j] << ' ';
                }
                cout << '\n';
            }
        }
        void Spread();
        bool IsValid(int y, int x) const { return y >= 0 && x >= 0 && y < f_Row && x < f_Column; }
        void CleanAir();
        void DoClean() {
            Spread();
            CleanAir();
        }
        int CalcDust() {
            int sum = 0;
            for(int i=0; i<f_Row; i++) {
                for(int j=0; j<f_Column; j++) {
                    if(field[i][j] != -1) {
                        sum += field[i][j];
                    }
                }
            }
            return sum;
        }
};
 
void Cleaner::CleanAir() {
    // 공기청정기 위치 찾기
    int upper = -1, lower = -1;
    for (int i = 0; i < f_Row; ++i) {
        if (field[i][0] == -1) {
            if (upper == -1) upper = i;
            else lower = i;
        }
    }

    // 위쪽 반시계 방향 순환
    for (int i = upper - 1; i > 0; --i) field[i][0] = field[i - 1][0];
    for (int i = 0; i < f_Column - 1; ++i) field[0][i] = field[0][i + 1];
    for (int i = 0; i < upper; ++i) field[i][f_Column - 1] = field[i + 1][f_Column - 1];
    for (int i = f_Column - 1; i > 1; --i) field[upper][i] = field[upper][i - 1];
    field[upper][1] = 0;

    // 아래쪽 시계 방향 순환
    for (int i = lower + 1; i < f_Row - 1; ++i) field[i][0] = field[i + 1][0];
    for (int i = 0; i < f_Column - 1; ++i) field[f_Row - 1][i] = field[f_Row - 1][i + 1];
    for (int i = f_Row - 1; i > lower; --i) field[i][f_Column - 1] = field[i - 1][f_Column - 1];
    for (int i = f_Column - 1; i > 1; --i) field[lower][i] = field[lower][i - 1];
    field[lower][1] = 0;
}


void Cleaner::Spread() {
    Field newField(f_Row, vector<int>(f_Column, 0));

    for (int i = 0; i < f_Row; i++) {
        for (int j = 0; j < f_Column; j++) {
            if (field[i][j] == -1) {
                newField[i][j] = -1;  // 공기청정기는 그대로 유지
                continue;
            }

            int curValue = field[i][j];
            if (curValue == 0) continue;

            int spreadAmount = curValue / 5;
            int spreadCount = 0;

            for (int d = 0; d < 4; d++) {
                int ny = i + dirY[d];
                int nx = j + dirX[d];

                if (IsValid(ny, nx) && field[ny][nx] != -1) {
                    newField[ny][nx] += spreadAmount;
                    spreadCount++;
                }
            }

            newField[i][j] += curValue - (spreadAmount * spreadCount);
        }
    }

    field = newField;  // 원본 맵 갱신
}


int main()
{
    FastIO
    int R, C, T;
    cin >> R >> C >> T;
    
    Cleaner cl(R, C);
    
    cl.InitField();
    
    for(int i=0; i<T; i++) {
        cl.DoClean();
    }
    
    cout << cl.CalcDust();
}