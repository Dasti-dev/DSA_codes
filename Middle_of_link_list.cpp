// Online C++ compiler to run C++ program online
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
//reversing approach1 [  O(n) and O(1)  ]
void reverse1( Node* &head )
{
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    while(curr != NULL)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
//reversing approach 2 
void reverse2 ( Node* &head , Node* curr , Node* prev)
{
    if ( curr == NULL )
    {
        head = prev;
        return;
    }
    Node* next = curr -> next;
    reverse2( head , next , curr );
    curr -> next = prev;
}
//rever recursion 2 [ O(n) and O(n) ]
Node* reverse3 ( Node* &head )
{
    if ( head == NULL || head -> next == NULL )
    {
        return head;
    }
    Node* smallHead = reverse3 ( head -> next );
    head -> next -> next = head;
    head -> next = NULL;
    return smallHead;
}
//middle of linked list 
int middle1 ( Node* head )
{
    Node* fast = head;
    Node* slow = head;
    while( fast -> next != NULL )
    {
        slow = slow -> next;
        if( fast -> next -> next != NULL )
        {
            fast = fast -> next -> next;   
        }
        else 
        {
            return slow->data;
        }
    }
    return slow->data;
}
//middle by length method
int middle2 ( Node* head )
{
    Node* tmp = head;
    int count = 1;
    while( tmp -> next != NULL )
    {
        tmp = tmp -> next;
        count++;
    }
    Node* reach = head;
    {
        count = count / 2;
        while( count-- )
        {
            reach = reach -> next;
        }
    }
    return reach->data;
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
    //reversing ll
    reverse1(mid);
    print(mid);
    cout << middle1(mid) << endl;
    cout << middle2(mid) << endl;
    // reverse using recusion
    Node* curr = mid;
    Node* prev = NULL;
    reverse2( mid , curr , prev );
    print(mid);
    Node* start = reverse3(mid);
    print(start);
    //middle of linked list
    cout << middle1(start) << endl;
    cout << middle2(start) << endl;
    return 0;
}
