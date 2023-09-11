#include <stdio.h>


int main()
{
    int bucket[100] = {0,};
    int bucketCnt, ballCnt;
    scanf("%d %d", &bucketCnt, &ballCnt);
    
    int i, j, k;
    for(int x = 0; x<ballCnt; x++){
        scanf("%d %d %d", &i, &j, &k);
        for(int l = i-1; l<=j-1; l++){
            bucket[l] = k;
        }
    }
    
    for (int i = 0; i<bucketCnt; i++){
        printf("%d ", bucket[i]);
    }
    return 0;
}