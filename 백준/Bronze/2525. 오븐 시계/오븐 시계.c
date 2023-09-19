int main()
{
    int hour, min;
    int cookingTime;
    scanf("%d %d", &hour, &min);
    scanf("%d", &cookingTime);
    
    min += cookingTime;
    
    hour+= min/60;
    min%= 60;
    hour = hour%24;
    printf("%d %d",hour,min);
}