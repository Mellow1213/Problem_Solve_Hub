#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<long long> length(N-1);
    vector<long long> price(N);
    for(int i=0; i<N-1; i++) {
        cin >> length[i];
    }
    for(int i=0; i<N; i++) {
        cin >> price[i];
    }
    long long lowest = price[0];
    long long sum = price[0] * length[0];
    
    for(int i=1; i<N-1; i++) {
        if(lowest > price[i]) {
            lowest = price[i];
        }
        sum += lowest * length[i];
    }
    cout << sum;
}