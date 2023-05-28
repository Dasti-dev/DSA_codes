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
    if( head == NULL )
    {
        Node* node = new Node(val);
        head = node;
        return;
    }
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
// Add 2 number
Node* sum( Node* &head1 , Node* &head2 )
{
    int count1 = 0;
    int count2 = 0;
    Node* hea1 = head1;
    Node* hea2 = head2;
    while( hea1 != NULL )
    {
        head1 = head1 -> next;
        count1++;
    }
    while( hea2 != NULL )
    {
        head2 = head2 -> next;
        count2++;
    }
    int count = 0 ;
    
    Node* curr1 = head1;
    Node* prev1 = NULL;
    Node* next1 = NULL;
    while( curr1 != NULL )
    {
        next1 = curr1 -> next;
        curr1 -> next = prev1;
        prev1 = curr1;
        curr1 = next1;
    }
    Node* curr2 = head2;
    Node* prev2 = NULL;
    Node* next2 = NULL;
    while( curr2 != NULL )
    {
        next2 = curr2 -> next;
        curr2 -> next = prev2;
        prev2 = curr2;
        curr2 = next2;
    }
    
    if ( count1 > count2 )
    {
        count = count1;
        while(count--)
        {
            insertAtEnd(prev1,0);
        }
    }
    
    else
    {
        count = count2;
        while(count--)
        {
            insertAtEnd(prev2,0);
        }
    }
    
    int carry = 0;
    int val = 0; 
    Node* newList = NULL;
    while( count-- )
    {
            int val = prev1->data + prev2->data;
            if( carry == 1)
                val = val + 1;
            if ( val > 9 )
            {
                val = val % 10;
                carry = 1;
            }
            else 
            {
                carry = 0;
            }
            insertAtEnd(newList,val);
            prev1 = prev1->next;
            prev2 = prev2->next;
    }
    Node* curr = newList;
    Node* prev = NULL;
    Node* next = NULL;
    
    while( curr != NULL )
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    while ( prev->data == 0 )
    {
        prev = prev -> next;
    }
    print(prev);
    return prev;
}
int main() {
    
    Node* head1 = NULL;
    
    insertAtEnd(head1,3);
    insertAtEnd(head1,5);
    // insertAtEnd(head1,7);
    // insertAtEnd(head1,9);
    
    Node* head2 = new Node(2);
    
    insertAtEnd(head2,6);
    insertAtEnd(head2,1);
    // insertAtEnd(head2,13);
    
    print(head1);
    print(head2);
    
    Node* node = sum(head1,head2);
    print(node);


    return 0;
}
