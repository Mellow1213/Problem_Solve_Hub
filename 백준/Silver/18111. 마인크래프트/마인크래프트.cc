#include <iostream>
#include <climits>
using namespace std;


int main()
{
    int N, M, amount;
    int UseTime = INT_MAX;
    int GroundHeight = 0;
    cin >> N >> M >> amount;
    
    int ground[N][M];
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> ground[i][j];
        }
    }
    
    for(int i=0; i<=256; i++){
        int needTime = 0;
        int needBlock = 0;
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                int blockDelta = 0;
                blockDelta = i - ground[j][k];
                
                needBlock += blockDelta;
                needTime += blockDelta >=0 ? blockDelta : -blockDelta*2;
            }
        }
        
        if(needBlock <= amount && needTime <= UseTime) { 
            UseTime = needTime;
            GroundHeight = i;
        }
    }
    cout << UseTime << " " << GroundHeight;
}