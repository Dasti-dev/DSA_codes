#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <bit>
#include <map>
#include <climits>

using namespace std;

int main() {
    
    
    vector<int> v = {2,1,5,4,3,0,0};
    
    // sort(v.begin(),v.end());
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
    
    // Three step process 
    // find break point from where you have to change
    // Then next digit which would be jus next to avaliable
    // arrange in asecding order 
    
    int ptr = -1;
    
    for(int i = v.size()-1 ; i > 0 ; i--)
    {
        if(v[i-1]<v[i])
        {
            ptr = i-1;
            break;
        }
    }
    
    int mini = v[ptr+1];
    int cnt;
    
    for(int i = ptr+1 ; i < v.size() ; i++)
    {
        if(v[i] < mini && v[i] > v[ptr])
        {
            cnt = i;
        }
    }
    
    swap(v[cnt],v[ptr]);
    
    sort(v.begin()+ptr+1,v.end());
    
    // print array
    for(int  i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
    return 0;
}
