#include <iostream>
using namespace std;

class Queue{
    int* arr;
    inline void moveNext(int& ptr){ ptr = (ptr+1) % capacity_; }
    int size_;
    int capacity_;
    int front_;
    int rear_;
    
    public:
        Queue(int s){
            capacity_ = s;
            arr = new int[s];
            size_ = 0;
            front_ = 0;
            rear_ = 0;
        }
        
        ~Queue(){
            delete[] arr;
        }
        
        void push(int e){
            if(size_>=capacity_){
                reserve(capacity_*2);
            }
            arr[rear_] = e;
            moveNext(rear_);
            size_++;
        }
        
        int pop(){
            if(size_ <= 0)   return -1;
            int back = arr[front_];
            moveNext(front_);
            size_--;
            return back;
        }
        
        int size(){
            return size_;
        }
        
        bool empty(){
            return size_<=0;
        }
        
        int front(){
            return (empty() ? -1 : arr[front_]);
        }
        
        int back(){
            if(size_ <= 0) return -1;  // 비어있으면 -1 반환
            return arr[(rear_ - 1 + capacity_) % capacity_];  // 원형 큐 고려
        }
        
        void reserve(int cap) {
            if(cap > capacity_) {
                int* new_arr = new int[cap];
                // 현재 front_부터 시작해서 size_만큼 순차적으로 복사
                for(int i = 0; i < size_; i++) {
                    new_arr[i] = arr[(front_ + i) % capacity_];
                }
                delete[] arr;
                arr = new_arr;
                front_ = 0;
                rear_ = size_;  // rear_는 다음 삽입 위치이므로 size_
                capacity_ = cap;
            }
        }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int commandCnt;
    cin >> commandCnt;
    Queue q(4);
    
    string command;
    for(int i=0; i<commandCnt; i++){
        cin >> command;
        switch(command[0]) {  // 첫 글자로 비교
            case 'p':
                if(command[1] == 'u') {  // push
                    int temp;
                    cin >> temp;
                    q.push(temp);
                }
                else {  // pop
                    cout << q.pop() << '\n';
                }
                break;
            case 'f':  // front
                cout << q.front() << '\n';
                break;
            case 'b':  // back
                cout << q.back() << '\n';
                break;
            case 's':  // size
                cout << q.size() << '\n';
                break;
            case 'e':  // empty
                cout << (q.empty() ? 1 : 0) << '\n';
                break;
        }
    }
    
    return 0;
}