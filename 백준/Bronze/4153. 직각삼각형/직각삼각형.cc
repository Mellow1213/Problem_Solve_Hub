#include <iostream>

using namespace std;

void Swap(int &num1, int &num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

int main()
{
    int A,B,C;
    
    while(1){
        string answer;
       cin >> A >> B >> C; 
       if(A == 0 && B == 0 && C == 0){
           break;
       }
          
       if(A>B) Swap(A, B);
       if(B>C) Swap(B, C);
       if(A>C) Swap(A, C);
       
       if(A*A + B*B == C*C){
           answer = "right";
       }
       else{
           answer = "wrong";
       }
       cout << answer << '\n';
    }
}
