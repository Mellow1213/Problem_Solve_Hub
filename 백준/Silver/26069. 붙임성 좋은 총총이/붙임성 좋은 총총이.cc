#include <iostream>
#include <unordered_set>

using namespace std;

const string originStr = "ChongChong";
unordered_set<string> uset;

static bool CheckInfest(string& str1, string& str2) {
    return str1==originStr || str2==originStr || uset.find(str1) != uset.end() || uset.find(str2) != uset.end();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    string meetA, meetB;
    for(int i=0; i<N; i++) {
        cin >> meetA >> meetB;
        if(!CheckInfest(meetA, meetB)) continue;
        if(uset.find(meetA) == uset.end()) 
            uset.insert(meetA);
        if(uset.find(meetB) == uset.end()) 
            uset.insert(meetB);
    }
    cout << uset.size();
}