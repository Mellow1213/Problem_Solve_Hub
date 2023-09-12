#include <stdio.h>

int main()
{
    int num[10];
    
    
    for(int i = 0 ; i<10; i++){
        scanf("%d", &num[i]);
        num[i] = num[i] % 42;
    }
    
    int result=0;
    
    for(int i=0; i<10; i++){
        int cnt = 0;
        for(int j=i+1; j<10; j++)
            if(num[i]==num[j])
                cnt=1;
        
        if(cnt==0)
            result++;
    }
    
    printf("%d", result);
}