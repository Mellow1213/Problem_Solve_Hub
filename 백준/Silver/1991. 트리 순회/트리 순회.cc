#include <iostream>
#include <vector>

using namespace std;


struct Node{
    char name;
    char leftChild;
    char rightChild;
};

vector<Node> nodeArr;

void Preorder(char ch){
    if(ch=='.') return;
    
    cout << ch;
    Preorder(nodeArr[ch-'A'].leftChild);
    Preorder(nodeArr[ch-'A'].rightChild);
}

void Inorder(char ch){
    if(ch=='.') return;
    
    Inorder(nodeArr[ch-'A'].leftChild);
    cout << ch;
    Inorder(nodeArr[ch-'A'].rightChild);
}

void Postorder(char ch){
    
    if(ch=='.') return;
    
    Postorder(nodeArr[ch-'A'].leftChild);
    Postorder(nodeArr[ch-'A'].rightChild);
    cout << ch;
}

int main()
{
    int N;
    cin >> N;
    
    nodeArr.resize(N);
    
    for(int i=0; i<N; i++){
        Node node;
        cin >> node.name >> node.leftChild >> node.rightChild;
        nodeArr[node.name-'A'] = node;
    }
    
    Preorder(nodeArr[0].name);
    cout <<'\n';
    Inorder(nodeArr[0].name);
    cout <<'\n';
    Postorder(nodeArr[0].name);
}