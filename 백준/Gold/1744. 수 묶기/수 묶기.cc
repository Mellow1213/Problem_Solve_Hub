#include <iostream>
#include <vector>
#include <algorithm>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

bool larger(int i, int j) {
    return i > j;
}


int main()
{
    FastIO
    int N;
    cin >> N;
    vector<int> arrM;
    vector<int> arrP;
    int zeroCnt = 0;
    arrM.reserve(N);
    arrP.reserve(N);
    int sum = 0;
    for(int i=0; i<N; i++) {
        int inputNum;
        cin >> inputNum;
        if(inputNum>0) {
            arrP.push_back(inputNum);
        } else if(inputNum < 0) {
            arrM.push_back(inputNum);
        } else {
            zeroCnt++;
        }
    }
    
    sort(arrM.begin(), arrM.end());
    sort(arrP.begin(), arrP.end(), larger);
    
    for(int i=0; i+1<arrM.size(); i+=2) {
        sum += arrM[i]*arrM[i+1];
    }
    if(arrM.size()%2==1) {
        if(zeroCnt > 0) {
            zeroCnt--;
        }
        else {
            sum += arrM[arrM.size()-1];
        }
    }
    
    for(int i=0; i+1<arrP.size(); i+=2) {
        int plus = arrP[i]+arrP[i+1];
        int tim = arrP[i]*arrP[i+1];
        if(plus > tim)
            sum += plus;
        else
            sum += tim;
    }
    if(arrP.size()%2==1) {
        sum += arrP[arrP.size()-1];
    }
    
    cout << sum;
}