#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int d){
        this -> data = d;
        this -> next = nullptr;
    }
    //destructor
    ~Node(){
        //curr obj ka data value mein store kr li
        int value = this -> data;
        if(this -> next != nullptr){
            delete next;
            next = nullptr;

        }
        cout<< " memory is free for node with data = "<<value<<endl;
    }
};
//insertion
void insertNode(Node *&tail, int element, int d){
    //empty list
    if(tail == nullptr) {
        Node* newNode = new Node(d);
        tail = newNode = new Node(d);
        newNode -> next = newNode;

    }
    else{
        //non empty list
        //assuming that the element present in the list

        Node* curr = tail;
        while(curr -> data != element){
            curr = curr -> next;

        }
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr-> next = temp;
    }

}
// for traaversing or printing all
void print(Node* tail){
    Node* temp = tail;
    //empty list
    if(tail == nullptr){
        cout<<"list is empty"<<endl;
        return;

    }
    do{
        cout<< tail -> data << " ";
        tail = tail -> next;

    } 
    while (tail != temp);
    cout << endl;
}
//deleting node
void deleteNode(Node* tail,int value){
    //empty list
    if(tail == NULL)
    {
        cout<<"list is empty, toh kya delete keroge"<<endl;

    }else{
        //non empty
        //assuming that value is present in the ll
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value){
            //dono ko aage bdhte rho , curr and prev ko bhi
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = curr -> next;

        // 1 node ll
        if(curr == prev){
            tail = NULL;
            
        }
        //>=2 node ll
        else if(tail == curr){
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
}
int main(){
    Node* tail = nullptr;
    insertNode(tail, 5,3);
    print(tail);

   /* insertNode(tail,3,5);
    print(tail);

    insertNode(tail,5,7);
    print(tail);

    insertNode(tail,7,9);
    print(tail);

    insertNode(tail,5,6);
    print(tail); */

    deleteNode(tail,3 );
    print(tail);

}