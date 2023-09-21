#include <iostream>

using namespace std;

int main()
{
    string text;
    int len;
    
    cin>>text;
    len = text.length();
    
    
    bool flag = true;
    for(int i = 0; i<len/2; i++){
        if(text[i] != text[len-1-i]){
            flag = false;
            break;
        }
    }
    
    cout<<flag;
}