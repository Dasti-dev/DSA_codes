#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    
    vector<int> v = {1,0,0,2,3,4,0,0,0,5,6,7,0,0,8,9,10,0,11};
    // sort(v.begin(),v.end());
    // print array
    for(int  i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    // BRUTE FORCE SOLUTION
    // TC -> O(N) + O(N-n) + O(n)
    // SC -> O(n)
    // copy all the non zero numbers in tmp[]
    // copy it back to original array
    // put zero in the end
    
    //OPTIMAL SOLUTION
    // Use 2 pointer approach
    int j = -1;
    for(int i = 0 ; i < v.size() ; i++)
    {
        if(v[i] == 0)
        {
            j = i ;
            break;
        }
    }
    for(int i = j+1 ; i < v.size() ; i++)
    {
        if(v[i] != 0)
        {
            swap(v[i],v[j]);
            j++;
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
