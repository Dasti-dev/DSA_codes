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
    
    // OPTIMAL SOLUTION
    // TC -> O(n1+n2)
    // SC -> O(1)
    int i = 0 ;
    int j = 0 ;
    vector<int> inter ;
    while(i < v1.size() && j < v2.size())
    {
        if(v1[i] == v2[j])
        {
            inter.push_back(v1[i]);
            i++;
            j++;
        }
        else if(v1[i] < v2[j])
        {
            i++;
        }
        else if(v1[i] > v2[j])
        {
            j++;
        }
    }
    // print array
    for(int  i = 0 ; i < inter.size() ; i++)
    {
        cout << inter[i] << " ";
    }
    cout << endl;
    
    return 0;
}
