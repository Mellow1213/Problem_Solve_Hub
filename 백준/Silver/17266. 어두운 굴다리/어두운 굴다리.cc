#include <iostream>
#include <vector>
using namespace std;

class ExpressCo_ {
    int lightCnt;
    vector<int> lightPos;
    int roadLength;
    bool IsCover(int height) {
        int lastCovered = 0;
        
        for(int i=0; i<lightCnt; i++) {
            int leftRange = lightPos[i] - height;
            int rightRange = lightPos[i] + height;
            
            if(leftRange > lastCovered) return false;
            
            lastCovered = max(rightRange, lastCovered);
        }
        
        return lastCovered >= roadLength;
    }
    public:
        ExpressCo_(int len, int cnt, vector<int>& vec) : 
                roadLength(len), lightCnt(cnt), lightPos(vec) { }
        void FindHeight() {
            int left = 0;
            int right = roadLength;
            
            while(left < right) {
                int curHeight = ( left + right ) / 2;
                if(IsCover(curHeight)) {
                    right = curHeight;
                } else {
                    left = curHeight + 1;
                }
            }
            
            cout << left;
        }
        
};

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> lights(M);
    for(int i=0; i<M; i++) {
        cin >> lights[i];
    }
    
    ExpressCo_ ex(N, M, lights);
    ex.FindHeight();
}