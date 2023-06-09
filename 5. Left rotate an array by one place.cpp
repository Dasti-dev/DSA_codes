#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    
    vector<int> v = {3, 3, 5, 7, 9, 9, 11, 13, 13, 17, 17, 19, 22, 22, 14, 9, 4};
    sort(v.begin(),v.end());
    // print array
    for(int  i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    // ONLY SOLUTION
    // TC -> O(N)
    // SC -> O(N)
    int tmp = v[0];
    for(int i = 1 ; i < v.size() ; i++)
    {
        v[i-1] = v[i];
    }
    v[v.size()-1] = tmp;
    // print array
    for(int  i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
    
    return 0;
}
