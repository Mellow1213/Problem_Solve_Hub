#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int cnt;
    cin >> cnt;
    
    vector<int> origin(cnt);
    for (int i = 0; i < cnt; ++i) {
        cin >> origin[i];
    }
    
    vector<int> compress = origin;
    sort(compress.begin(), compress.end());
    compress.erase(unique(compress.begin(), compress.end()), compress.end());
    
    unordered_map<int, int> index_map;
    for (int i = 0; i < compress.size(); ++i) {
        index_map[compress[i]] = i;
    }
    
    for (const auto& val : origin) {
        cout << index_map[val] << ' ';
    }
    
    return 0;
}
