#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    
    vector<int> v1 = {1,2,3,4,5,6,7,0,8,74,10,11};
    vector<int> v2 = {6,28,8,94,53,6,74,05,0,2,04};
    
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    // print array
    for(int  i = 0 ; i < v1.size() ; i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;
    // print array
    for(int  i = 0 ; i < v2.size() ; i++)
    {
        cout << v2[i] << " ";
    }
    cout << endl;
    // BRUTE FORCE SOLUTION
    // Take a set and iterate 
    // TC -> O(nlogn) + O(nlogn) + O(2n)
    // SC -> O(2n)
    
    set<int> st;
    vector<int> uni;
    for(int i = 0 ; i < v1.size() ; i++)
    {
        st.insert(v1[i]);
    }
    for(int i = 0 ; i < v2.size() ; i++)
    {
        st.insert(v2[i]);
    }
    for( auto it : st )
    {
        uni.push_back(it);
    }
    // print array
    for(int  i = 0 ; i < uni.size() ; i++)
    {
        cout << uni[i] << " ";
    }
    cout << endl;
    
    // OPTIMAL SOLUTION
    
    vector<int> v;
    int i = 0 ;
    int j = 0 ;
    while( i < v1.size() && j < v2.size() )
    {
        if(v1[i] <= v2[j])
        {
            if(v.size() == 0 || v.back() != v1[i])
            {
                v.push_back(v1[i]);
            }
            i++;
        }
        else
        {
            if(v.size() == 0 || v.back() != v2[j])
            {
                v.push_back(v2[j]);
            }
            j++;
        }
    }
    while( j < v2.size() )
    {
        if(v.size() == 0 || v.back() != v2[j])
        {
            v.push_back(v2[j]);
        }
        j++;
    }
    while( i < v1.size() )
    {
        if(v.size() == 0 || v.back() != v1[i])
        {
            v.push_back(v1[i]);
        }
        i++;
    }
    // print array
    for(int  i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
    
    return 0;
}
