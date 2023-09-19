#include <stdio.h>
#include <stdbool.h>

int main()
{
    int year;
    scanf("%d",&year);
    
    bool isLeapYear = ( (year%4 == 0) && (year%100 != 0) )  ||  (year%400==0);
    
    if(isLeapYear)
        printf("1");
    else
        printf("0");
}