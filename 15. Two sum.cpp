// TWO SUM
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
    
    vector<int> v = {2,5,6,8,11};
    int target = 14;
    
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
    // Hashing
    // TC -> O(Nlogn)
    // SC -> O(N)
    map<int,int> m;
    vector<int> ans;
    int sum1 = 0;
    for(int i = 0 ; i < v.size() ; i++)
    {
        int sum1 = target - v[i];
        if(m.find(sum1) != m.end())
        {
            ans.push_back(m[sum1]);
            ans.push_back(i);
            cout << "YES" << endl;
            break;
        }
        m[v[i]] = i;
    }
    // print array
    for(int  i = 0 ; i < ans.size() ; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    // OPTIMAL SOLUTION
    // Greedy and 2 pointer
    // TC -> O(2N)
    // SC -> O(1)
    int i = 0;
    int j = v.size()-1;
    vector<int> sol;
    int sum = 0;
    while(i<=j)
    {
        sum = v[i] + v[j];
        if(sum == target)
        {
            sol.push_back(i);
            sol.push_back(j);
            break;
        }
        else if(sum < target)
        {
            i++;
        }
        else{
            j--;
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
