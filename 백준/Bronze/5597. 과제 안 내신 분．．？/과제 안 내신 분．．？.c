#include <stdio.h>
#include <stdbool.h>

int main()
{
    const int submitCnt=28;
    
    _Bool submit[30] = {false};
    int temp;
    
    for(int i =0; i<submitCnt; i++){
        scanf("%d", &temp);
        submit[temp-1] = 1;
    }
    
    for(int i=0 ; i<30; i++)
        if(submit[i]==0)
            printf("%d\n", i+1);
}