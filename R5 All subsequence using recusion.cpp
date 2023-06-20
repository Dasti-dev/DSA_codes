#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void print ( vector<int> v )
{
    for(int i = 0 ; i  < v.size() ; i++ )
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void subs (int i , vector<int> v , vector<int> arr , int n)
{
    if( i >= n)
    {
        print(arr);
        return;
    }
    // Take
    arr.push_back(v[i]);
    subs(i+1,v,arr,n);
    // Not take
    arr.pop_back();
    subs(i+1,v,arr,n);
}

int main() {
    
    vector<int> v = {3,2,1};
    
    subs(0,v,{},v.size());
    
    return 0;
}
