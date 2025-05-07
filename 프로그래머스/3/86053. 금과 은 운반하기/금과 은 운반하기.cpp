#include <climits>
#include <vector>

using namespace std;

bool IsPossible(int a, int b, vector<int>& g, vector<int>& s, vector<int>& w, vector<int>& t, long long T) {
    long long goldSum = 0;
    long long silverSum = 0;
    long long mixSum = 0;
    for(int i=0; i<g.size(); i++) {
        long long curG = g[i];
        long long curS = s[i];
        long long curW = w[i];
        long long curT = t[i];
        
        long long possibleTrip = T / (2*curT);
        if(T % (2*curT) >= curT)
            possibleTrip++;
        
        long long possibleWeight = possibleTrip * curW;
        
        goldSum += min(curG, possibleWeight);
        silverSum += min(curS, possibleWeight);
        mixSum += min(curG + curS, possibleWeight);     
    }
    return goldSum >= a && silverSum >= b && mixSum >= a+b;
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long left = 0;
    long long right = 10e14;
    while(left < right) {
        long long mid = (left + right) / 2;
        
        if(IsPossible(a, b, g, s, w, t, mid)) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}
