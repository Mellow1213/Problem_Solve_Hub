#include <iostream>
#include <vector>

using namespace std;

class stack{
    private:
        vector<int> arr;
        int size = -1;
    public:
        void Push(int element){
            arr.push_back(element);
            size++;
        }
        int Pop(){
            int temp = arr[size];
            arr.pop_back();
            size--;
            return temp;
        }
        int Size(){
            return size;
        }
};

int main()
{
    int testCase;
    stack s;
    int sum = 0;
    
    cin >> testCase;
    for(int i=0; i<testCase; i++){
        int inputNum;
        cin >> inputNum;
        
        if(inputNum == 0){
            s.Pop();
            continue;
        }
        
        s.Push(inputNum);
    }
    
    int size = s.Size();
    for(int i=0; i<=size; i++){
        sum += s.Pop();
    }
    
    cout << sum;
}
