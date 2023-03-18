#include<iostream>
using namespace std;

class Node{
    public:
    int data;

    Node* prev;

    Node* next;

    // creating a constructor
    Node(int d){
        this->data = d;
        this ->prev = NULL;
        this ->next = NULL;
    }

};
// traversing a LL
void print(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout<< temp ->data<<" ";
        temp = temp-> next;
    }
    cout<<endl;
}
// for geting length of LL
int getlength(Node*head){
    int len=0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}
void insertAtHead(Node* &head, int d){  // yhn par &(refernce nhi )dalne par vlue prnt nhi hio rhi thi
    // s-1 creating a node first
    Node* temp = new Node(d);
    //s-2  temp ke next ko head mein daal dunga
    temp-> next = head;
    //s-3 head ke prev ko temp mein daal dunga
    head -> prev = temp;
    // s-4 head galt postin par hai usko shi postn temp par daal dunga
    head = temp;
}
void insertAtTail(Node* &tail, int d){
    // s-1 creating a temp node jisko last mein add krna hai
    Node* temp = new Node(d);
    // s-2 
    tail->next = temp;
    // s-3
    temp->prev = tail;
    //s-4
    tail = temp;
}
int main(){

    Node* node1 = new Node(10);

    Node* head = node1;
    // ek tail node bna leta hun jo string mein head ki trh node1 ko point kr rhi hogi
    Node* tail = node1;
    print(head);

    // cout<<getlength(head)<<endl;

    //calling insrtathead function or prniting or adding a new node
    insertAtHead(head,12);
    print(head);

    // ek node aur daal dun
    insertAtHead(head,13);
    print(head);

    // ab last mein ek node dalta hun tail or
    insertAtTail(tail,35);
    print(head);

}


   