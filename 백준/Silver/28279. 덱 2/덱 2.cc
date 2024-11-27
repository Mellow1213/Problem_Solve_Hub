#include <iostream>
#include <cassert>

struct Node
{
    int value;
    Node *next;
    Node *prev;

    Node(int value) : value(value), next(nullptr), prev(nullptr) {}
};

class Custom_LinkedList
{
    Node *firstNode;
    Node *lastNode;
    int nodeAmount;

public:
    Custom_LinkedList();
    void push_front(int element);
    void push_back(int element);
    int front() const;
    int back() const;
    int pop_front();
    int pop_back();
    int size() const;
    bool isEmpty() const;
};

int Custom_LinkedList::back() const {
    return isEmpty() ? -1 : lastNode->value;
}

int Custom_LinkedList::front() const {
    return isEmpty() ? -1 : firstNode->value;
}

int Custom_LinkedList::pop_front(){
    if(isEmpty())   return -1;

    Node* temp = firstNode;
    int popValue = firstNode->value;

    if(nodeAmount == 1){
        firstNode = nullptr;
        lastNode = nullptr;
    } else {
        firstNode = firstNode->next;
        firstNode->prev = nullptr;
    }
    delete temp;
    nodeAmount--;
    return popValue;
}

int Custom_LinkedList::pop_back(){
    if(isEmpty())   return -1;

    Node* temp = lastNode;
    int popValue = lastNode->value;

    if(nodeAmount==1){
        firstNode = nullptr;
        lastNode = nullptr;
    } else {
        lastNode = lastNode->prev;
        lastNode->next = nullptr;
    }
    delete temp;
    nodeAmount--;
    return popValue;
}

int Custom_LinkedList::size() const {
    return nodeAmount;
}

bool Custom_LinkedList::isEmpty() const {
    return nodeAmount <= 0;
}

void Custom_LinkedList::push_back(int element)
{
    Node *newNode = new Node(element);
    if (nodeAmount == 0)
    {
        firstNode = newNode;
        lastNode = newNode;
    }
    else
    {
        newNode->prev = lastNode;
        lastNode->next = newNode;
        lastNode = newNode;
    }
    nodeAmount++;
}

void Custom_LinkedList::push_front(int element)
{
    Node *newNode = new Node(element);
    if (nodeAmount == 0)
    {
        firstNode = newNode;
        lastNode = newNode;
    }
    else
    {
        firstNode->prev = newNode;
        newNode->next = firstNode;
        firstNode = newNode;
    }
    nodeAmount++;
}

Custom_LinkedList::Custom_LinkedList()
{
    nodeAmount = 0;
    firstNode = nullptr;
    lastNode = nullptr;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    int commandCnt, command;
    Custom_LinkedList CL;
    std::cin >> commandCnt;
                int cache;
    for(int i=0; i<commandCnt; i++){
        std::cin >> command;
        assert(command>=1 && command<=8);
        switch(command){
            case 1:
                std::cin >> cache;
                CL.push_front(cache);
                break;
            case 2:
                std::cin >> cache;
                CL.push_back(cache);
                break;
            case 3:
                std::cout << CL.pop_front() << '\n';
                break;
            case 4:
                std::cout << CL.pop_back() << '\n';
                break;
            case 5:
                std::cout << CL.size() << '\n';
                break;
            case 6:
                std::cout << CL.isEmpty() << '\n';
                break;
            case 7:
                std::cout << CL.front() << '\n';
                break;
            case 8:
                std::cout << CL.back() << '\n';
                break;
        }
    }
}