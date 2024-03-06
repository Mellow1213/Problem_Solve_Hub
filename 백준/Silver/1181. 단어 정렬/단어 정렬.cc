#include <iostream>
#include <set>
#include <string>

using namespace std;

struct Compare{
    bool operator() (const string& a, const string& b) const{
        if(a.length()==b.length()){
            return a<b;
        }
        return a.length()<b.length();
    }
};

int main()
{
    set<string, Compare> words;
    int num;
    
    cin >> num;
    
    string temp;
    for(int i = 0; i< num ; i ++){
        cin >> temp;
        words.insert(temp);
    }
    
    for(auto iter = words.begin(); iter !=words.end(); ++iter){
        cout << *iter << "\n";
    }
}