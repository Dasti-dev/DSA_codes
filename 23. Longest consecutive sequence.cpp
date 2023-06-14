#include <vector>
#include <climits>
#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_set>


using namespace std;

bool ls( int tar , vector<int> v )
{
    for(int i = 0 ; i < v.size() ; i++)
    {
        if(tar == v[i])
        {
            return true;
        }
    }
    return false;
}

int main() {
    
    // longest consecutive sequence
    
    vector<int> v = {1,2,3,4,100,101,102,103,104};
    
    // print an array
    for(int i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
    // brute force

    int len = 1;
    for(int i = 0 ; i < v.size() ; i++)
    {
        int x = v[i];
        int cnt = 1;
        while(ls(x+1,v) == true)
        {
            x = x+1;
            cnt ++;
        }
        len = max(cnt,len);
    }
    cout << len << endl;
    
    // Better solution
    
    sort(v.begin(),v.end());
    int longest = 1;
    int small = -1;
    int cnt = 0;
    for(int i = 0 ; i < v.size() ; i++)
    {
        if(v[i]-1 == small)
        {
            small = v[i];
            cnt++;
        }
        else if(v[i] != small)
        {
            cnt = 1;
            small = v[i];
        }
        
        longest = max(longest,cnt);
    }
    cout << longest << endl;
    
    // Optimal solution
    // O(3n) and O(n) if set takes O(1)
    
    unordered_set<int> s;
    int count = 1;
    for(int i = 0 ; i < v.size() ; i++)
    {
        s.insert(v[i]);
    }
    
    for(auto it : s)
    {
        if(s.find(it-1) == s.end())
        {
            int cnt  = 1;
            int x = it;
            while(s.find(x+1) != s.end())
            {
                cnt++;
                x = x+1;
            }
            count = max(count,cnt);
        }
    }
    cout << count << endl;
    return 0;
}
