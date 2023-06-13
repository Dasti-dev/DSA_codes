#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <bit>
#include <map>
#include <climits>

using namespace std;

int main() {
    
    
    vector<int> v = {10,22,12,3,0,6};
    
    // sort(v.begin(),v.end());
    // sort(v2.begin(),v2.end());
    // print array
    for(int  i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
    // BRUTE FORCE SOLUTION
    // exists
    // O(n2)
    
    // BETTER SOLUTION 
    // Hashing
    // TC -> O(Nlogn)
    // SC -> O(N)
    
    // OPTIMAL SOLUTION
    // TC -> O(N + NlogN)
    // SC -> O(N)
    
    int maxi = -1;
    vector<int> sol;
    
    for(int i = v.size()-1 ; i > 0 ; i--)
    {
        if(v[i] > maxi)
        {
            sol.push_back(v[i]);
            maxi = v[i];
        }
    }
    // print array
    for(int  i = 0 ; i < sol.size() ; i++)
    {
        cout << sol[i] << " ";
    }
    cout << endl;
    
    return 0;
}
