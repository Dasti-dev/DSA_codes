#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    
    vector<int> v = {-2,-2,-2,-1,-1,-1,0,0,0,2,2,2,2};
    int sum = 0;
    
    // print array
    for(int i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
    // brute force 
    
    // better solution
    // hashing
    
    
    
    // optimal solution
    
    sort(v.begin(),v.end());
    
    vector<vector<int>> sol;
    
    for(int i = 0 ; i < v.size() ; i++)
    {
        if(i>0 && v[i] == v[i-1])
        {
            continue;
        }
        int j = i+1;
        int k = v.size() - 1;
        while(j<k)
        {
            
            if((v[i]+v[j]+v[k]) < sum)
            {
                j++;
            }
            else if((v[i]+v[j]+v[k]) > sum)
            {
                k--;
            }
            else if((v[i]+v[j]+v[k]) == sum)
            {
                vector<int> ans = {v[i],v[j],v[k]};
                sol.push_back(ans);
                j++;
                k--;
                while(j<k && v[j] == v[j-1]) j++;
                while(j<k && v[k] == v[k+1]) k--;
                
            }
        }
    }
    // print array
    for(int i = 0 ; i < sol.size() ; i++)
    {
        for(int j = 0 ; j < sol[i].size() ; j++)
        {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    return 0;
}
