#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <bit>

using namespace std;

int main() {
    
    vector<int> v = {1,2,3,4,5,6,7,8,10,11};
    // vector<int> v2 = {6,28,8,94,53,6,74,05,0,2,04};
    
    // sort(v1.begin(),v1.end());
    // sort(v2.begin(),v2.end());
    // print array
    for(int  i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    // BRUTE FORCE SOLUTION
    // TC -> O(N2)
    // SC -> O(1)
    for(int i = 1 ; i < v.size() ; i++)
    {
        int flag  = 0 ;
        for(int j = 0 ; j < v.size() ; j++)
        {
            if(v[j] == i)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            cout << i << endl;
            break;
        }
    }
    // BETTER SOLUTION 
    // Use Hashmap
    // TC -> O(2N)
    // SC -> O(N) 
    
    vector<int> hash(v.size(),0);
    
    for(int i = 0 ; i < v.size() ; i++)
    {
        hash[v[i]] = 1;
    }
    for(int i = 1  ; i < hash.size() ; i++)
    {
        if(hash[i] == 0)
        {
            cout << i << endl;
        }
    }
    
    // OPTIMAL SOLUTION
    // TC -> 
    // SC ->
    
    long long int total = ((v.size()+1)*(v.size()+2))/2;
    
    int sum = 0;
    for(int i = 0 ; i < v.size() ; i++)
    {
        sum = sum + v[i];
    }
    cout << total-sum << endl;
    
    // BETTER OPTIMAL SOLUTION
    int xo1 = 0 ;
    for(int i = 0 ; i < v.size() ; i++)
    {
        xo1 = xo1^v[i];
    }
    int xo2 = 0 ;
    for(int i = 0 ; i < v.size() ; i++)
    {
        xo2 = xo2^i;
    }
    
    cout << xo1 ^ xo2 ;
    return 0;
}
