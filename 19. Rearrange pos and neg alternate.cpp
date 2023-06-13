#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <bit>
#include <map>
#include <climits>

using namespace std;

int main() {
    
    // vector<int> v = {1,2,3,4,5,6,7,8,10,11};
    // vector<int> v = {0,0,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0};
    
    // vector<int> v2 = {6,28,8,94,53,6,74,05,0,2,04};
    
    vector<int> v = {3,1,-2,-5,2,-4,9};
    
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
    // take all positive at new array and negative at different array 
    // rearrange it in new array
    
    // BETTER SOLUTION 
    // Hashing
    // TC -> O(Nlogn)
    // SC -> O(N)
    
    // OPTIMAL SOLUTION
    // For equal negative positive
    // TC -> O(N)
    // SC -> O(N)
    vector<int> ans(v.size(),0);
    int even = 0;
    int odd = 1;
    
    for(int i = 0 ; i < v.size() ; i++)
    {
        if(v[i] > 0)
        {
            ans[even] = v[i];
            even += 2;
        }
        else
        {
            ans[odd] = v[i];
            odd += 2;
        }
    }
    // print array
    for(int  i = 0 ; i < ans.size() ; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    // BRUTE SOLUTION = OPTIMAL
    // For equal negative positive
    // TC -> O(N)
    // SC -> O(N)
    
    vector<int> pos;
    vector<int> neg;
    vector<int> sol(v.size(),0);
    for( int i = 0 ; i < v.size() ; i++)
    {
        if(v[i] > 0)
        {
            pos.push_back(v[i]);
        }
        else
        {
            neg.push_back(v[i]);
        }
    }
    
    if(pos.size() > neg.size())
    {
        for(int i = 0 ; i < neg.size() ; i++)
        {
            sol[2*i] = pos[i];
            neg[2*i+1] = neg[i];
        }
        int index = 2*neg.size();
        for(int i = neg.size() ; i < pos.size() ; i++)
        {
            sol[index] = pos[i];
            index++;
        }
    }
    else
    {
        for(int i = 0 ; i < pos.size() ; i++)
        {
            sol[2*i] = pos[i];
            neg[2*i+1] = neg[i];
        }
        int index = 2*pos.size();
        for(int i = pos.size() ; i < neg.size() ; i++)
        {
            sol[index] = neg[i];
            index++;
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
