#include <iostream>

using namespace std;

void add (int i , int sum)
{
    if(i < 1)
    {
        cout << sum << endl;
        return;
    }
    add (i-1,sum+i);
}

int addition (int n)
{
    if( n < 1)
    {
        return 0;
    }
    return addition(n-1) + n;
}

int fact (int n)
{
    if(n < 2)
    {
        return 1;
    }
    return fact(n-1)*n;
}

int main() {
    
    add(5,0);
    int n  = addition(5);
    cout << n << endl;
    int f  = fact(5);
    cout << f << endl;
    return 0;
}
