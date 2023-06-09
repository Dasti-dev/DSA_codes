#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    vector<int> v = {3, 5, 7, 9, 11, 13, 17, 19, 22, 14, 9 ,4};
    // BRUTE FORCE SOLUTION
    sort(v.begin(),v.end());
    cout << v[v.size()-1] << endl;
    // OPTIMAL SOLUTION
    int maxi = v[0];
    for(int i = 0 ; i < v.size() ; i++)
    {
        maxi = max(maxi,v[i]);
    }
    cout << maxi << endl;

    return 0;
}
