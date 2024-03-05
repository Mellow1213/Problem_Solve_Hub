#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    unordered_map<char, int> letterCountMap;
    string letter;
    cin >> letter;
    for(int i=0; i<letter.length(); i++){
        letter[i] = toupper(letter[i]);
        letterCountMap[letter[i]]++;
    }
    
    char mostUsedLetter = '\0';
    int mostUsedFrequency = 0;
    int samethingAppeared = 0;
    for(const auto& p : letterCountMap){
        if(p.second > mostUsedFrequency){
            mostUsedFrequency = p.second;
            mostUsedLetter = p.first;
        }
            
        else if(p.second == mostUsedFrequency){
            mostUsedLetter = '?';
        }
    } 
    
    cout << mostUsedLetter;
    
}