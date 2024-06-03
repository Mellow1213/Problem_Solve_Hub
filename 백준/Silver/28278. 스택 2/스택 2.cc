#include <iostream>
#include <vector>
using namespace std;

class stack{
    private:
        int index = -1;
        vector<int> v;
    public: 
        void push(int x);
        int pop();
        int size();
        bool empty();
        int top();
};

void stack::push(int x){
    v.push_back(x);
    index++;
}

int stack::pop(){
    if(index == -1) return -1;
    
    int p = v[index];
    v.pop_back();
    index--;
    return p;
}

int stack::size(){
    return index+1;
}

bool stack::empty(){
    return size() == 0;
}

int stack::top(){
    return empty() ? -1 : v[index];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    stack s;
    int command;
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> command;
        switch(command){
            case 1:
                int num;
                cin >> num;
                s.push(num);
                break;
            case 2:
                cout << s.pop() << '\n';
                break;
            case 3:
                cout << s.size() << '\n';
                break;
            case 4:
                cout << s.empty() << '\n';
                break;
            case 5:
                cout << s.top() << '\n';
                break;
        }
    }
}
