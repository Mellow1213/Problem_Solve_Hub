#include <stdio.h>

int main()
{
    int testCnt; //N
    float testBestScore; //M
    
    scanf("%d", &testCnt);
    
    float testArr[testCnt];
    
    for(int i = 0; i< testCnt; i++){
        scanf("%f", &testArr[i]);
        if(testArr[i] > testBestScore)
            testBestScore = testArr[i];
    }
    
    float sum = 0;
    for(int i = 0 ; i<testCnt; i++){
        testArr[i] = (testArr[i]/testBestScore)*100;
        sum += testArr[i];
    }
    
    printf("%f", (sum/testCnt));
}
