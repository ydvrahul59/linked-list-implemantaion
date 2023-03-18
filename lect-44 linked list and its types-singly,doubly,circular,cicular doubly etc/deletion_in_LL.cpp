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

    //creating destructor for deleting the elmnt in LL
    ~Node(){
        int value = this ->data;
        //memory free code
        if(this-> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout<<"memory is free for node  with data = "<<value<<endl;
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
//creating a function for insertin at any possition in linked list
void insertAtPosition( Node* &tail,Node* &head,int position,int d){
    // insert at start
    if(position == 1){
        insertathead(head,d);
        return ;
    }
    //sabse phle mujhe traverse krna hai toh maine ek node* temp bna liya jo ki strting mein head ko show krga
    Node* temp = head;
    //jo current position hai, starting mein pahli node par dunga
    int cnt = 1;
    while(cnt<position-1){
        temp = temp -> next;
        cnt++;
    }
    //insertin at last position
    if(temp -> next == NULL){
        insertattail(tail, d);
        return ;
    }
    //ab int d ke liye ek node bana lo
    //creating a node for d
    Node* nodeTOInsert = new Node(d);
    
    nodeTOInsert -> next = temp -> next;

    temp -> next = nodeTOInsert;
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
// creating function for deleting node
void deleteNode(int position, Node* &head){
    if(position == 1){
        //deleting first node or start node
        Node* temp = head; //ek variable bna liya temp namme ka jo head ko point kr rha hoga
        head = head -> next;
        //memory free start node
        temp ->next = NULL; // koi bhi node ko hatne se phle usko null ko point kra denge tki segmntation fault na aaye
        delete temp;
    }
    else{
        //deletin any middle or last node
        //pahle 2 pointer bna lenge
        Node* curr = head;// ye staartin mein curr. head ko pont kr rha hoga
        Node* prev = NULL; // ye starting mein prev. NULL hoga

        int cnt = 1;
        while (cnt< position){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
        
    }
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

    // ab 12 & 15 ke bich 22 daal do
   // insertAtPosition(head,3/*position that u wnt to insrt*/,22/*elmnt that u wnt to insrt*/);
    //print(head); // 10 12 22 15

    /* yhn par kuch cases jaise 1st position par kuch daal nhi skten kyunki string hin phli position se ho rkhi hai 
    but if(position ==1 ) in insertatposition funct*/

    insertAtPosition(tail,head,1,23); // insertin at first positon
    print(head);

    insertAtPosition(tail,head,4,25);
    print(head);

    cout<<"head = "<<head ->data<<endl;
    cout<<"tail = "<<tail ->data<<endl;

    // deleting first node
    deleteNode(1,head);
    print(head);
// deleting last node
    deleteNode(4,head);
    print(head);
// delteting now 2nd node
    deleteNode(2,head);
    print(head);

}