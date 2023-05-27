#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    
    Node(int d)
    {
        this -> data = d;
        this -> next = NULL;
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

// k reverse 
Node* kreverse( Node* &head , int k )
{
    Node* next = NULL;
    Node* prev = NULL;
    Node* curr = head;
    int count = 0;
    while ( curr != NULL && count < k )
    {
        next = curr -> next;
        curr -> next  = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    if ( next != NULL )
    {
        head -> next = kreverse(next,k);
    }
    
    return prev;
}
int main() {
    Node* mid = new Node(1);
    //making a linked list
    insertAtEnd(mid,2);
    insertAtEnd(mid,3);
    insertAtEnd(mid,4);
    insertAtEnd(mid,5);
    insertAtEnd(mid,6);
    insertAtEnd(mid,7);
    insertAtEnd(mid,8);
    insertAtEnd(mid,9);
    //printing ll
    print(mid);
    // k reversing ll
    Node* start = kreverse(mid,2);
    print(start);
    
    return 0;
}
