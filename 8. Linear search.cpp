#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    
    vector<int> v = {1,0,0,2,3,4,0,0,0,5,6,7,0,0,8,9,10,0,11};
    sort(v.begin(),v.end());
    // print array
    for(int  i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    // LINEAR SEARCH
    for(int i = 0 ; i < v.size() ; i++)
    {
        if(v[i] == target)
        {
            cout << i << endl;
        }
    }
    
    
    
    return 0;
}
