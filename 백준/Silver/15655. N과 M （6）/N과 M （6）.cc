/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> outStream;
vector<int> sequence;

void BackTrack(int index, int depth) {
    if(depth >= M) {
        for(const auto& p : outStream) {
            cout << p << ' ';
        }
        cout <<'\n';
        return;
    }
    
    for(int i = index; i < N; i++) {
        if(outStream[outStream.size()-1] >= sequence[i]) {
            continue;
        }
        
        outStream.push_back(sequence[i]);
        BackTrack(i, depth+1);
        outStream.pop_back();
    }
}

int main()
{
    cin >> N >> M;
    sequence.assign(N, 0);
    outStream.reserve(M);
    
    for(int i=0; i<N; i++) {
        cin >> sequence[i];
    }
    
    sort(sequence.begin(), sequence.end());
    
    BackTrack(0, 0);
}