#include <iostream>
#include <string>
using namespace std;
int main()
{
    string text, text_r;
    int flag;
    
    
    while(1){
        flag = 0;
        cin >> text;
        if(text=="0")
            break;
        for(int i=0; i<text.length()/2; i++){
            if(text[i] != text[text.length()-i-1]){
                flag = 1;
                break;
            }
        }
    
        cout << (flag == 0 ? "yes" : "no")<<"\n";   
    }   
    
}