// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node {
    public: 
    int data;
    Node* next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};
// insert new element at end
void insertAtEnd ( Node* &head , int val )
{
    Node* node = new Node(val);
    Node* tmp = head ;
    while( tmp -> next != NULL )
    {
        tmp = tmp -> next;
    }
    tmp -> next = node;
}
//insert new element at start
void insertAtStart ( Node* &tail , int val )
{
    Node* node = new Node(val);
    node -> next = tail;
    tail = node;
}
//insert in middle
void insertAtMiddle ( Node* &head , int position , int val )
{
    Node* node = new Node(val);
    Node* tmp = head;
    position--;
    while( --position )
    {
        tmp = tmp -> next;
    }
    node -> next = tmp -> next;
    tmp -> next = node;
}
//print a linked list
void print ( Node* &head )
{
    Node* tmp = head;
    while( tmp != NULL )
    {
        cout << tmp -> data << " ";
        tmp = tmp -> next;
    }
    cout << endl;
}
//delete a node
void deleteNode ( int position , Node* &head )
{
    Node* tmp = head;
    if ( position == 1)
    {
        Node* sec = head;
        head = head -> next;
        sec -> next = NULL;
        delete sec;
        return ;
    }
    position--;
    while( --position > 0 )
    {
        tmp = tmp -> next;
    }
    Node* sec = tmp -> next;
    tmp -> next = tmp -> next -> next;
    tmp = sec;
    tmp -> next = NULL;
    delete tmp;
}


int main() {
    
    Node* mid = new Node(5);
    print(mid);
    //add in start
    insertAtStart(mid,3);
    print(mid);
    //inset at end
    insertAtEnd(mid,7);
    print(mid);
    //insert in middle
    insertAtMiddle(mid,2,4);
    print(mid);
    //delete a node
    deleteNode(1,mid);
    print(mid);

    return 0;
}
