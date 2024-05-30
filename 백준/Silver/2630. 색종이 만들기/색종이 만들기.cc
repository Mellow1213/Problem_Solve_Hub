#include <iostream>
#include <vector>

using namespace std;

int white = 0, blue =0;

int CheckOnlyColor(vector<vector<bool>> vec, int x, int y, int size){
    int color = vec[x][y];
    for(int i=x; i<x+size; ++i){
        for(int j=y; j<y+size; ++j){
            if(vec[i][j] != color){
                return false;
            }
        }
    }
    return true;
}

void SeparatePaper(const vector<vector<bool>>& paper, int x, int y, int size){
    if(CheckOnlyColor(paper, x, y, size)){
        if(paper[x][y] == 1)
            blue++;
        else
            white++;
        return;
    }
    
    int newSize = size/2;
    SeparatePaper(paper, x, y, newSize);
    SeparatePaper(paper, x, y + newSize, newSize);
    SeparatePaper(paper, x + newSize, y, newSize);
    SeparatePaper(paper, x + newSize, y + newSize, newSize);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    vector<vector<bool>> paper(N, vector<bool>(N, false));
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int a;
            cin >> a;
            if(a)
                paper[i][j] = true;
        }
    }
    
    SeparatePaper(paper, 0, 0, N);
    
    cout << white << '\n' << blue;
}
