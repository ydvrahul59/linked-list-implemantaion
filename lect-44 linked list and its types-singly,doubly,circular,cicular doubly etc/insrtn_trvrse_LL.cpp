// insertin at start/head and end/tail in linked list
#include<iostream>
using namespace std;
class Node{
    public:
    int data;

    Node* next;

    //creating constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL ;
    }
};
//create a function for insertion
void insertathead(Node* &head,int d){
    //new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;

}
// creating a function for tail
void insertattail(Node* &tail, int d){
    //new node create krni pdegi
    Node* temp = new Node(d);
    //tail ka nxt ,temp hai
    tail -> next = temp;
    // tail alwys lst node ko point krga
    tail = tail -> next; //tail = temp;
}
//traversing linked list
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){
    //created a new node
    Node* node1 = new Node(10); //jab koi new node bne toh us time constructor call hoga,line 10
    

    Node* head = node1;
    Node* tail = node1;
    print(head);
   // cout<<node1 -> data<<endl;  //otput will be 10
    //cout<<node1 -> next<<endl;  //output will be garbage value

    //head pointed to node1
  /*  Node* head = node1;
    print(head); //op.=10

    insertathead(head,12);
    print(head); // 12,10

    insertathead(head,15);
    print(head); //15, 12 ,10 */
    /* but yhn opt ulta aa rha hai 15, 12, 10 but hum chaten hain 10,12, 15 aaye uske liye 
       hume ab ek TAIL introduce krna pdega,   jaise head ka use kr ke insert at head kr rha tha toh strting wli postion pr node add ho rha tha
       usi parkar ek function bnuga jiska name insert at tail hoga wo alwys ending node ke aage new node add krega,
       TAIL - (1.) ek pointer hoga node type ka,  (2.)jo ki alwys last node ko show krga*/
      
    //calling insertattail function
    insertattail(tail,12);
    print(head);//10,12

    insertattail(tail,15);
    print(head); //10,12,15
}   