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


//sentinel nodes eliminate edge cases like empty list,single node list or insertion/removal at boundaries
class LRUCache{
public:

    unordered_map<int,Node*> cache;
        //so that we directly get the address of the required item through node without searching the whole list
        //hence keeping time complexity o(1) rather than o(n)
    int capacity;
        //LRU's maximum capacity
    Node* head;
    Node* tail;


//FUNCTION
    LRUCache(int cap){
        capacity = cap;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);

        head->next=tail;
        tail->prev=head;
    }
// connecting head and tail in constructor using sentinel nodes 
    

//FUNCTION
    void insertFront(Node* node){

        node->next=head->next;
        node->prev=head;

        head->next->prev=node;
        head->next=node;
            // adding a new node just after the head so it becomes the most recently used item
            // this is a O(1) opereation as we are just changing pointers and not shifiting array elements 
    }
//FUNCTION
    void remove(Node* node){

        Node* p=node->prev;
        Node* n=node->next;

        p->next=n;
        n->prev=p;
            // we are just connecting the previous and next neighbours directly which effectively
            // skips the node and removes it, this is also a O(1) operation as we use the node itself and no searching is required
    }
//FUNCTION
    void print(){

        Node* curr=head->next;

        while(curr!=tail){
            cout<<"("<<curr->key<<","<<curr->value<<") ";
            curr=curr->next;
        }

        cout<<endl;
    }
    //just printing the entire node list from head->next to tail in pairs(key,value)

//FUNCTION(helper function)
    void moveToFront(Node* node){
        remove(node);
        insertFront(node);
    }

    int get(int key){
        if(cache.find(key)==cache.end())  //  |
            return -1;                    //  |
                                          //  | hashmap lookup
        Node* node = cache[key];          //  | takes O(1)

        moveToFront(node); //removing and move to front both performed in O(1) TC here also
            //if the node is present in the cache then it becomes the most recently used 
            //item and hence will be moved to front
        return node->value;
    }

    void put(int key, int value){
         //if node with same key is present already 
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            node->value = value;
            moveToFront(node);
//----------------------------will need to add return here when we sort out the common code at last--------------------------------------------------------------------------------------------
        }
        //now two more cases
        //1) if not present and cache has space left
        //2) if not present and cache is full
        else{
            if(cache.size()==capacity){//means full
                Node* LRU = tail-> prev;
                remove(LRU);                   //removed from doubly linked list
                cache.erase(LRU->key);          // delete from hashmaps
                delete LRU;                     // delete it
                //least recently used node deleted

                //now make a new node and assign it the value
                Node* node= new Node(key,value);
                insertFront(node);
                cache[key]=node;

            }
            else{
                Node* node= new Node(key,value);
                insertFront(node);
                cache[key]=node;
            }

            
        }
        
    }
};

int main(){

    LRUCache cache(3);
        // 3 is the maximum capacity
    Node* A=new Node(1,10);
    Node* B=new Node(2,20);
    Node* C=new Node(3,30);

    cache.insertFront(A);
    cache.insertFront(B);
    cache.insertFront(C);

    cache.print();

    return 0;
}