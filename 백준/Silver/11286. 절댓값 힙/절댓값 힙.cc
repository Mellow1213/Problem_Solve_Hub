#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>  // for abs()

using namespace std;

class AbsoluteHeap{
    private:
        vector<int> vec; 
    public:
        AbsoluteHeap(){
            vec.push_back(0);  // 1-based indexing
        }
        bool IsSmall(int parent, int child){
            if (abs(parent) > abs(child)) {
                return true;
            }
            if (abs(parent) == abs(child) && parent > child) {
                return true;
            }
            return false;
        }
        void push(int x){
            vec.push_back(x);
            
            int child = vec.size() - 1;
            int parent = child / 2;
            
            while (child > 1 && IsSmall(vec[parent], vec[child])) {
                swap(vec[parent], vec[child]);
                child = parent;
                parent = child / 2;
            }
        }
        void pop(){
            if (vec.size() == 1) {
                cout << 0 << "\n";
                return;
            }
            
            int result = vec[1];
            vec[1] = vec.back();
            vec.pop_back();
            
            int parent = 1;
            int child = parent * 2;
            int size = vec.size();
            
            while (child < size) {
                if (child + 1 < size && IsSmall(vec[child], vec[child + 1])) {
                    child++;
                }
                if (!IsSmall(vec[parent], vec[child])) {
                    break;
                }
                swap(vec[parent], vec[child]);
                parent = child;
                child = parent * 2;
            }
            
            cout << result << "\n";
        }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    AbsoluteHeap ah;
    
    cin >> N;
    
    int command;
    for (int i = 0; i < N; i++) {
        cin >> command;
        if (command == 0) {
            ah.pop();
        }
        else {
            ah.push(command);
        }
    }
    return 0;
}
