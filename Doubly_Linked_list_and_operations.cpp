#include <iostream>
using namespace std;

class Node {
    public: 
        int data;
        Node* prev;
        Node* next;
    Node (int d)
    {
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }
};
//print the linked list
void print(Node* &head)
{
    Node* tmp = head;
    while( tmp != NULL)
    {
        cout << tmp -> data << " ";
        tmp = tmp -> next;
    }
    cout << endl;
}
//get length of Linked list
void getLength (Node* &head)
{
    Node* tmp = head ;
    int len  = 0; 
    while( tmp != NULL )
    {
        tmp = tmp -> next;
        len++;
    }
    cout << len << endl;
}
//insert at start
void insertAtStart (Node* &head , int val )
{
    if ( head == NULL )
    {
        Node* node = new Node(val);
        head = node;
        return;
    }
    Node* node = new Node(val);
    node -> next = head;
    head -> prev = node;
    head = node;
}
//insert at end
void insertAtEnd (Node* &head , int val )
{
    Node* node = new Node(val);
    Node* tmp = head;
    while( tmp -> next != NULL )
    {
        tmp = tmp -> next;
    }
    tmp -> next = node;
    node -> prev = tmp;
}
//insert in middle
void insertAtMiddle (Node* &head , int position , int val )
{
    Node* node = new Node(val);
    Node* tmp = head ;
    if ( position == 1 )
    {
        node -> next = head;
        head -> prev = node;
        head = node;
        return;
    }
    position--;
    while( --position > 0)
    {
        tmp = tmp -> next;
    }
    node -> next = tmp -> next ;
    node -> prev = tmp ;
    tmp -> next = node;
    if ( tmp -> next != NULL )
    {
        Node* sec = tmp -> next;
        sec -> prev = node;
    }
}
// deletion at linklist
void deleteNode ( Node* &head , int position )
{
    Node* tmp = head;
    if( position == 1 )
    {
        head = head -> next;
        tmp -> next  = NULL;
        delete tmp;
        return;
    }
    position--;
    while ( --position )
    {
        tmp = tmp -> next ;
    }
    Node* sec = tmp -> next;
    tmp -> next = sec -> next;
    sec -> next -> prev = tmp;
    sec -> next = NULL;
    sec -> prev = NULL;
    delete sec;
}
int main() {
    // Write C++ code here
    Node* mid = new Node(10);
    print(mid);
    getLength(mid);
    //insert at start
    insertAtStart(mid,5);
    print(mid);
    //insert at end
    insertAtEnd(mid,15);
    print(mid);
    //insert at middle
    insertAtMiddle(mid,1,0);
    print(mid);
    //delete a node
    deleteNode(mid,1);
    print(mid);

    return 0;
}
