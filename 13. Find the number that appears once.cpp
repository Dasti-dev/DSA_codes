#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <bit>

using namespace std;

int main() {
    
    // vector<int> v = {1,2,3,4,5,6,7,8,10,11};
    // vector<int> v = {0,0,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0};
    
    // vector<int> v2 = {6,28,8,94,53,6,74,05,0,2,04};
    
    vector<int> v = {1,1,2,2,3,3,4,4,5,5,6,7,7,8,8,9,9};
    
    // sort(v1.begin(),v1.end());
    // sort(v2.begin(),v2.end());
    // print array
    for(int  i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
    // BRUTE FORCE SOLUTION
    
    // exists
    
    // BETTER SOLUTION 
    
    // Hash exists
    
    // OPTIMAL SOLUTION
    // TC -> 
    // SC ->
    
    int xo = 0;
    for(int i = 0 ; i < v.size() ; i++)
    {
        xo = xo^v[i];
    }
    
    cout << xo << endl;
    
    return 0;
}
