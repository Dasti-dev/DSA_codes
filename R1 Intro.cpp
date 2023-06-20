#include <iostream>

using namespace std;

void name(int n)
{
    if(n<=0)
        return;
    cout << "hello" << endl;
    n--;
    name(n);
}

void numberhl(int n)
{
    cout << n << endl;
    if(n <= 1)
     return;
    n--;
    numberhl(n);
}

void numberlh(int n)
{
    if(n <= 1)
    {
        return;
    } 
    n--;
    numberlh(n);
    cout << n+1 << endl;
}

int main() {
    
    int n = 5;
    name(n);
    numberhl(n);
    numberlh(n);
    return 0;
}
