#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string text;
    int wordCnt;
    
    
    getline(cin, text);
    
    wordCnt = 1;
    
    if(text.length() == 1 && text[0]==' '){
        cout << 0;
        return 0;
    }
    
    for(int i=1; i<text.length()-1; i++){
        if(text[i] == ' ') wordCnt++;
    }

    cout << wordCnt;
}