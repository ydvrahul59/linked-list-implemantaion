//node implemention using c++
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
int main(){
    Node* node1 = new Node(10);

    cout<<node1 -> data<<endl;  //otput will be 10
    cout<<node1 -> next<<endl;  //output will be garbage value
}