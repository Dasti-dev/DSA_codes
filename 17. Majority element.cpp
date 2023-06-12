
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <bit>
#include <map>

using namespace std;

int main() {
    
    // vector<int> v = {1,2,3,4,5,6,7,8,10,11};
    // vector<int> v = {0,0,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0};
    
    // vector<int> v2 = {6,28,8,94,53,6,74,05,0,2,04};
    
    vector<int> v = {1,0,2,1,1,1,1,0,2,1,1,1,0,2,1,1,2,1,1,2,1,1,1};
    
    // sort(v1.begin(),v1.end());
    // sort(v2.begin(),v2.end());
    // print array
    for(int  i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
    // BRUTE FORCE SOLUTION
    // esists
    
    // BETTER SOLUTION 
    // Hashing
    // TC -> O(Nlogn)
    // SC -> O(N)
    
    map<int,int> m;
    
    for(int i = 0 ; i < v.size() ; i++)
    {
            m[v[i]]++;
    }
    for(auto it:m)
    {
        if(it.second > v.size()/2)
        {
            cout << it.first << endl;
        }
    }
    
    // OPTIMAL SOLUTION
    // MOORES VOTING ALGORITHM
    // TC -> O(N + N)
    // SC -> O(1)
    
    int cnt = 0;
    int ele;
    for(int i = 0 ; i < v.size() ; i++)
    {
        if(cnt == 0)
        {
            ele = v[i];
            cnt = 1;
        }
        else if(v[i] == ele)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    cnt = 0 ;
    for( int i = 0 ; i < v.size() ; i++ )
    {
        if(v[i] == ele)
        cnt++;
    }
    
    if(cnt > v.size()/2)
    {
        cout << ele << endl;
    }
    
    return 0;
}
