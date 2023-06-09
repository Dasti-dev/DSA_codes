#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    
    vector<int> v = {3, 3, 5, 7, 9, 9, 11, 13, 13, 17, 17, 19, 22, 22, 14, 9, 4};
    sort(v.begin(),v.end());
    for(int  i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    // BRUTE FORCE SOLUTION
    // TC -> NlogN + N
    // SC -> O(N)
    set<int> st;
    for(int i = 0 ; i < v.size() ; i++)
    {
        st.insert(v[i]);
    }
    int index = 0;
    for( auto it:st )
    {
        v[index] = it;
        index++;
    }
    cout << index << endl;
    
    // BETTER SOLUTION
    // 2 pointer approach
    // TC -> O(N)
    // SC -> O(1)
    int p = 0;
    for( int j = 1 ; j < v.size() ; j++ )
    {
        if(v[j] != v[p])
        {
            v[p+1] = v[j];
            p++;
        }
    }
    cout << p+1 << endl;
    for(int  i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
    
    return 0;
}
