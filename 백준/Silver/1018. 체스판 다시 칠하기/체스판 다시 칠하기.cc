#include <iostream>
using namespace std;

int main()
{
    int N, M;
    
    cin >> N >> M;
    
    char board[N][M];
    
    for(int i = 0; i<N; i++){
        for(int j=0; j<M; j++)
            cin >> board[i][j];
    }
    
    
    
    int minChange = 64;
    
    for(int i=0; i<= N-8; i++){ // 8X8 이상의 체스판을 자르기 위해 최소 순회
        for(int j=0; j<= M-8; j++){
            
            
            int changeW = 0;
            int changeB = 0;
            
            for(int k=i;k< i+8; k++){ // 8X8체스판 하나를 칠해봄
                for(int l = j; l < j+8; l++){
                    
                    if((k+l)%2==0) // 현재 예상 패턴이 첫번째 색과 같음
                    { 
                        if(board[k][l] != 'W') changeW++;
                        if(board[k][l] != 'B') changeB++;
                    }
                    else // 현재 예상 패턴이 첫번째 색과 다름
                    {
                        if(board[k][l] != 'B') changeW++;
                        if(board[k][l] != 'W') changeB++;
                    }
                }
            }
            // 순회 중의 8X8 체스판을 잘랐을 때 W가 좋은지 B가 좋은지
            minChange = min(minChange, min(changeB, changeW));
            
        }
    }
    
    cout << minChange;
}