#include<bits/stdc++.h>
using namespace std;

class Node {

    public: 

    int data;
    Node* next;

    //constructure
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    //deconstructor
    ~Node(){
        int value = this -> data;
        //memory free
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};

void insertAtHead(Node* &head, int d){

    //create a new node
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}



void insertAtTail(Node* &tail,int d){

    Node* temp = new Node(d);
    tail ->next = temp;
    tail = temp;
}


void insertAtposition(Node* &tail, Node* &head, int position, int d){

    //insert at start
    if(position == 1){
        insertAtHead(head,d);
        return;
    }

    Node* temp = head;
    int cnt =1;

    while(cnt < position-1){
        temp = temp -> next;
        cnt++;
    }

    //insert at last
    if(temp -> next == NULL){
        insertAtTail(tail,d);
        return;
    }

    //creating new node
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}


void deleteNode(int position, Node* &head, Node* &tail){

    //deleting for first node or starting node
    if(position == 1){
        Node* temp = head;
        head = head -> next;
        //memory free start node 
        temp -> next = NULL;
        delete temp;
    }
    else{

        //delete middle or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while( cnt < position){
            prev = curr;
            curr = curr -> next;
            cnt++;
            
        }
        prev -> next = curr -> next;

        //handling tail if last node is delete
        if(curr -> next == NULL) tail = prev;

        curr -> next = NULL;
        delete curr;
    }
}



void print(Node* &head){
    if(head == NULL){
        cout << "The list is empty" << endl;
        return;
    }
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<< endl;
}





int main(){
    //create new node 
    Node* node1 = new Node(10);
    // cout << node1 -> data << endl;
    // cout << node1 -> next << endl;

    //head pointed to node1
    Node* head = node1;
    print(head);


    Node* tail = node1;


    insertAtTail(tail, 12);
    print(head);

    insertAtTail(tail, 13);
    print(head);


    insertAtposition(tail, head, 4, 20);
    print(head);


    cout << "head " << head -> data <<endl;
    cout << "tail " << tail -> data <<endl;


    deleteNode(4, head, tail);
    print(head);
    
    cout << "head " << head -> data <<endl;
    cout << "tail " << tail -> data <<endl;





    return 0;
}