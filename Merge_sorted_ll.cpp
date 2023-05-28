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
    tmp -> next -> next = NULL;
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
//merge sorted linked list
Node* merged ( Node* &head1 , Node* &head2 )
{
    Node* newHead = NULL;
    Node* prev = head1;
    Node* curr = head1;
    Node* tmp = head2;
    if ( head1 == NULL )
    {
        return head2;
    }
    if ( head2 == NULL )
    {
        return head1;
    }
    if( curr->data < tmp->data )
    {
        newHead = head1;
    }
    else 
    {
        newHead = head2;
    }
    while ( curr != NULL && tmp != NULL )
    {
        if ( curr->next == NULL && curr->data < tmp->data )
        {
            curr -> next  = tmp;
            tmp = tmp -> next;
            prev = prev -> next;
            curr = curr -> next;
            prev -> next = NULL;
        }
        else if ( curr->data < tmp->data && curr->next->data > tmp->data )
        {
            curr = curr -> next;
            prev -> next = tmp;
            tmp = tmp -> next;
            prev = prev -> next;
            prev -> next = curr;
            prev = prev -> next;
        }
        else if ( curr->data > tmp->data )
        {
            prev = tmp;
            tmp = tmp -> next;
            prev -> next = curr;
            prev = prev -> next;
        }
        else if ( curr->next->data < tmp->data && curr->next != NULL )
        {
            prev = prev -> next;
            curr = curr -> next;
        }
    }
    return newHead;
}
int main() {
    
    Node* head1 = new Node(1);
    
    insertAtEnd(head1,3);
    insertAtEnd(head1,5);
    insertAtEnd(head1,7);
    insertAtEnd(head1,9);
    
    Node* head2 = new Node(2);
    
    insertAtEnd(head2,6);
    insertAtEnd(head2,10);
    insertAtEnd(head2,13);
    
    print(head1);
    print(head2);
    
    Node* merge = merged(head1,head2);
    print(merge);

    return 0;
}
