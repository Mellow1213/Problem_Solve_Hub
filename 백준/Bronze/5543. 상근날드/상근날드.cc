#include <iostream>
using namespace std;

int min(int a, int b){
    return a<b ? a : b;
}

int main()
{
    int lowBurger = 2000, lowDrink = 2000;
    int temp;
    
    for(int i=0; i<3; i++){
        cin >> temp;
        lowBurger = min(temp, lowBurger);
    }
    for(int i=0; i<2; i++){
        cin >> temp;
        lowDrink = min(temp, lowDrink);
    }
    
    cout << lowDrink + lowBurger - 50;
}