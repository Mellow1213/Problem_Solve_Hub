#include <stdio.h>
#include <stdbool.h>
int main()
{
    int dice1, dice2, dice3;
    
    int reward;
    
    scanf("%d %d %d", &dice1, &dice2, &dice3);
    bool correct[3];
    correct[0] = dice1==dice2;
    correct[1] = dice2==dice3;
    correct[2] = dice1==dice3;
    
    
    if(correct[0] && correct[1])
        reward = 10000+ dice1*1000;
    else{
        if(correct[0])
            reward = 1000+dice1*100;
        else if(correct[1])
            reward = 1000+dice2*100;
        else if(correct[2])
            reward = 1000+dice3*100;
        
        
        else{ 
            if(dice1 > dice2 && dice1 > dice3)
                reward = dice1*100;
            else if(dice2 > dice1 && dice2 > dice3)
                reward = dice2*100;
            else
                reward = dice3*100;
        }
    }
    
    printf("%d", reward);
}