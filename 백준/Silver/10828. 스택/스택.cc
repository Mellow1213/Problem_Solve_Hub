#include <iostream>
#include <string>
using namespace std;

class Stack{
    private:
        int top;
        int maxStack;
        int* stack;
    public:
        Stack(int max){
            top = -1;
            maxStack = max;
            stack = new int[max];
        }
        void Push(int e);
        void Pop();
        void Size();
        void Empty();
        void Top();
        
};



void Stack::Push(int e){
    if(top < maxStack-1){
        stack[++top] = e;
    }
}

void Stack::Pop(){
    if(top > -1)
        cout << stack[top--] << '\n';
    else
        cout << -1 << '\n';
}

void Stack::Size(){
    cout << top+1 << '\n';
}

void Stack::Empty(){
    cout << (top <= -1 ? 1 : 0) << '\n';
}

void Stack::Top(){
    cout << (top > -1 ? stack[top]: -1) << '\n';
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    int N;
    
    cin >> N;
    
    Stack s(N);
    string command;
    
    for(int i=0; i<N; i++){
        cin >> command;
        
        if(command == "push"){
            int temp;
            cin >> temp;
            s.Push(temp);
        }
        else if(command == "pop"){
            s.Pop();
        }
        else if(command == "size"){
            s.Size();
        }
        else if(command == "empty"){
            s.Empty();
        }
        else if(command == "top"){
            s.Top();
        }
    }
}
