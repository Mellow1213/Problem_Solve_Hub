#include <iostream>
using namespace std;

void sortA(int* a){
    for(int i=0; i<2; i++){
        if(*(a+i) > *(a+i+1)){
            int t = *(a+i);
            *(a+i) = *(a+i+1);
            *(a+i+1) = t;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string message;
    int lines[3];
    while(1){
        cin >> lines[0] >> lines[1] >> lines[2];
        if(lines[0]==0 && lines[1]==0 && lines[2]==0){
            break;
        }
        
        sortA(lines);
        int a = lines[0];
        int b = lines[1];
        int c = lines[2];
        
        if(a+b<=c){
            message = "Invalid";
        }
        else if(a==b && b==c){
            message = "Equilateral";
        }
        else if(a==b || b==c || c==a){
            message = "Isosceles";
        }
        else{
            message = "Scalene";
        }
        cout << message << '\n';
    }
}