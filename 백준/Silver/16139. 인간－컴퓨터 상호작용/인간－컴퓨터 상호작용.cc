#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

static void SetFastIOS() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);  cout.tie(0);    
}

class ScanLetter {
    private: 
        string str;
        int size;
        vector<vector<int>> arr;
        void InitVector();
    public:
        ScanLetter(string str);
        int ScanChar(char targetChar, int start, int end);
};

ScanLetter::ScanLetter(string str) : str(str) {
    size = str.size();
    arr.assign(26, vector<int>(size, 0)); // a ~ z
    InitVector();
}

void ScanLetter::InitVector() {
    arr[str[0]-'a'][0] = 1;
    for(int i=1; i<size; i++) {
        for(int j=0; j<26; j++) {
            arr[j][i] = arr[j][i-1];
        }
        arr[str[i]-'a'][i]++;
    }
}

int ScanLetter::ScanChar(char ch, int st, int ed) {
    const int idx = ch - 'a';
    int cnt = 0;
    if(st != 0) {
        cnt = arr[idx][ed] - arr[idx][st-1];
    } else if (st == 0){
        cnt = arr[idx][ed];
    }
    
    return cnt;
}

int main()
{
    SetFastIOS();
    string str;
    int testcase;
    cin >> str >> testcase;
    ScanLetter sl(str);
    for(int i=0; i<testcase; i++) {
        char ch;
        int st, ed;
        cin >> ch >> st >> ed;
        assert(ch >= 'a' && ch <= 'z');
        assert(st >= 0 && ed <= str.size());
        cout << sl.ScanChar(ch, st, ed) << '\n';
    }
    
}