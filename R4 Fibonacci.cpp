#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int fib (int n)
{
    if ( n <= 1 )
    {
        return 0;
    }
    if ( n == 2 )
    {
        return 1;
    }
    return fib(n-1) + fib(n-2);
}

int main() {
    
    int n = 5;
    
    int ans = fib(n);
    
    cout << n << "th fibonacci number is :: " << ans; 
    
    return 0;
}
