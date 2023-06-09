#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    vector<int> v = {3, 5, 7, 9, 11, 13, 17, 19, 22, 14, 9 ,4};
    // BRUTE FORCE SOLUTION
    sort(v.begin(),v.end());
    int largest = v[v.size()-1];
    int second = 0;
    for(int i = v.size()-2 ; i >= 0 ; i--)
    {
        if(v[i] != largest)
        {
            second = v[i];
            break;            
        }
    }
    cout << second << endl;
    // BETTER SOLUTION
    int maxi = v[0];
    for(int i = 0 ; i < v.size() ; i++)
    {
        maxi = max(maxi,v[i]);
    }
    second = -1;
    for(int i = 0 ; i < v.size() ; i++)
    {
        if(v[i] != maxi)
        {
            second = max(second,v[i]);
        }
    }
    cout << second << endl;
    // OPTIMAL SOLUTION
    // 2 pointer approach
    largest = v[0];
    int slargest = -1;
    for(int i = 0 ; i < v.size() ; i++)
    {
        if(v[i] > largest)
        {
            slargest = largest ;
            largest = v[i];
        }
    }
    cout << slargest << endl;

    return 0;
}
