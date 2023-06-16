#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    
    vector<int> v = {2,1,1,3,1,4,5,6};
    int n = 8;
    
    // print array
    for(int i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
    // brute force 
    
    // better solution
    // hashing
    
    map<int,int> m;
    int maj = n/3;
    vector<int> ans;
    
    for(int i = 0 ; i < v.size() ; i++)
    {
            m[v[i]]++;
            if(m[v[i]] == maj+1)
            {
                ans.push_back(v[i]);
            }
    }
    // print array
    for(int i = 0 ; i < ans.size() ; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    // optimal solution
    
    int cnt1 = 0;
    int cnt2 = 0;
    int ele1 ;
    int ele2 ;
    
    for(int i = 0 ; i < v.size() ; i++)
    {
        if(cnt1 == 0 && v[i] != ele2)
        {
            ele1 = v[i];
            cnt1 = 1;
        }
        else if(cnt2 == 0 && v[i] != ele1)
        {
            ele2 = v[i];
            cnt2 = 1;
        }
        else if(ele1 == v[i])
        {
            cnt1++;
        }
        else if(ele2 == v[i])
        {
            cnt2++;
        }
        else 
        {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0 ; cnt2 = 0;
    vector<int> sol;
    for(int i = 0 ; i < v.size() ; i++)
    {
        if(v[i] == ele1)
        {
            cnt1++;
        }
        else if(v[i] == ele2)
        {
            cnt2++;
        }
    }
    if(cnt1 > maj)
    {
        sol.push_back(ele1);
    }
    if(cnt2 > maj)
    {
        sol.push_back(ele2);
    }
    // print array
    for(int i = 0 ; i < sol.size() ; i++)
    {
        cout << sol[i] << " ";
    }
    cout << endl;

    return 0;
}
