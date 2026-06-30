#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int key;
    int value;

    Node* prev;
    Node* next;

    Node(int k,int v){
        key=k;
        value=v;
        prev=NULL;
        next=NULL;
    }
};

int main(){

    Node* A=new Node(1,10);

    cout<<"Key: "<<A->key<<endl;
    cout<<"Value: "<<A->value<<endl;

    return 0;
}