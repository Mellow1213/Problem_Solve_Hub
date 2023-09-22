#include <iostream>

using namespace std;

int main()
{
    int cnt = 0;
    string inputLetter; 
    
    cin>>inputLetter;
    
    for(int i=0;i<inputLetter.length();i++){
        switch(inputLetter[i]){
            case 'c':
                if(inputLetter[i+1]=='=' || inputLetter[i+1]=='-'){
                    i++;
                }
                break;
            case 'd':
                if(inputLetter[i+1]=='z' && inputLetter[i+2]=='='){
                    i+=2;
                }
                else if(inputLetter[i+1]=='-')
                    i++;
                break;
            case 'l':
                if(inputLetter[i+1]=='j')
                    i++;
                break;
            case 'n':
                if(inputLetter[i+1]=='j')
                    i++;
                break;
            case 's':
                if(inputLetter[i+1]=='=')
                    i++;
                break;
            case 'z':
                if(inputLetter[i+1]=='=')
                    i++;
                break;
        }
        cnt++;
    }
    
    
    cout<<cnt;
    
}