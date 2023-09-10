#include <stdio.h>

int main()
{
    int cnt = 9;
    
    int temp;
    
    int bigNumber = 0;
    int index = 0;
    
    
    for(int i = 0; i<cnt; i++){
        scanf("%d", &temp);
        
        if(temp>bigNumber){
            bigNumber=temp;
            index = i;
        }
    }
    
    
    printf("%d\n%d",bigNumber, (index+1));
    return 0;
}