#include <iostream>

using namespace std;

int main()
{
    int whitePaper[100][100] = {0,};
    int colorPaperAmount;
    int cnt = 0;
    
    cin >> colorPaperAmount;
    
    int locations[colorPaperAmount][2];
    
    for(int i=0; i<colorPaperAmount; i++){
        cin >> locations[i][0] >> locations[i][1];
    }
    
    for(int k=0; k<colorPaperAmount; k++)
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++)
            whitePaper[locations[k][0]+i][locations[k][1]+j] = 1;
        }
        
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(whitePaper[i][j]==1){
                cnt++;
            }
        }
    }
    cout<<cnt;
}
