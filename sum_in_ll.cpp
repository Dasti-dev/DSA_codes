#include <iostream>
using namespace std;

class Node {
    public: 
    int val;
    Node* next;
    Node(int d)
    {
        this->val = d;
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
void print ( Node* &head )
{
    Node* tmp = head;
    while( tmp != NULL )
    {
        cout << tmp -> val << " ";
        tmp = tmp -> next;
    }
    cout << endl;
}

Node* add ( Node* &l1 , Node* &l2 )
{
Node* ans = new Node(-1);
    Node* it = ans;
        int carry = 0;
        while((l1 != NULL || l2 != NULL) || (carry != 0) )
        {
            int sum = 0;
            if (l1 != NULL && l2 != NULL)
            {
                sum = l1->val + l2->val;
            }
            else if (l1 == NULL && l2 != NULL)
            {
                sum = l2->val;
            }
            else if (l2 == NULL && l1 != NULL)
            {
                sum = l1->val;
            }
            else if (l1 == NULL && l2 == NULL)
            {
                sum = carry;
                carry = 0;
            }
            
            if(carry > 0)
            {
                sum = sum + carry;
                carry = 0;
            }
            if(sum > 9)
            {
                sum = sum%10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            // cout << "sum " << sum << endl;
            // cout << "carry " << carry << endl;
            Node* node = new Node(sum);
            it->next = node ;
            it = it->next;
            if(l1 != NULL && l2 != NULL)
            {
                l1 = l1 -> next;
                l2 = l2 -> next;
            }
            else if(l1 != NULL && l2 == NULL)
            {
                l1 = l1->next;
            }
            else if(l2 != NULL && l1 == NULL)
            {
                l2 = l2->next;
            }
            
        }
        ans = ans->next;
        
        return ans;
}

int main() {
    Node* first = new Node(1);
    insertAtEnd(first,8);
    // insertAtEnd(first,0);
    print(first);
    Node* second = new Node(0);
    insertAtEnd(second,5);
    insertAtEnd(second,5);
    print(second);
    Node* sum = add(first,second);
    print(sum);
    return 0;
}
