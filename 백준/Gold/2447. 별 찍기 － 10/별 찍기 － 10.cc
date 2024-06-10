#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> starField;

void InitVectorSize(int size){
    starField.resize(size, vector<char>(size, ' '));
}

void DrawStar(int x, int y, int size){
    if(size==1)
    {
        starField[x][y] = '*';
        return;
    }
    
    int newSize = size/3;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i == 1 && j == 1){
                continue;
            }
            DrawStar(x+i*newSize, y+j*newSize, newSize);
        }
    }
}

void PrintStar(){
    int size = starField.size();
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cout << starField[i][j];
        }
        cout << '\n';
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int N;
    cin >> N;
    InitVectorSize(N);
    DrawStar(0, 0, N);
    PrintStar();
}
