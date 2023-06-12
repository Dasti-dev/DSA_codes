// Sort an array 012
// Duetch National Flag Algorithm
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
    
    vector<int> v = {1,0,2,0,1,0,1,0,2,1,0,2,1,2,0,0,2,1,0,2,1,2,0};
    
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
    // Count 1s 2s 0s , and manually overwrite arrays
    
    // BETTER SOLUTION 
    // TC -> O(Nlogn)
    // SC -> O(N)

    // OPTIMAL SOLUTION
    // DUETCH NATIONAL FLAG ALGORITHM
    // TC -> O(N + NlogN)
    // SC -> O(1)
    int low = 0;
    int mid = 0;
    int high = v.size()-1;
    
    while(mid <= high)
    {
        if(v[mid] == 0)
        {
            swap(v[low],v[mid]);
            mid++;low++;
        }
        else if(v[mid] == 1)
        {
            mid++;
        }
        else if(v[mid] == 2)
        {
            swap(v[high],v[mid]);
            high--;
        }
    }
    // print array
    for(int  i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
