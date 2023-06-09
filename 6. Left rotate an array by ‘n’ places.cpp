#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    
    vector<int> v = {1,2,3,4,5,6,7,8,9,10,11};
    sort(v.begin(),v.end());
    // print array
    for(int  i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    // BRUTE FORCE SOLUTION
    // TC -> O(N) + O(N-n) + O(n)
    // SC -> O(n)
    int n = 50;
    n = 50 % v.size();
    cout << v.size() << " " << n << endl;
    vector<int> tmp;
    for(int i = 0 ; i < n ; i++)
    {
        tmp.push_back(v[i]);
    }
    for(int i = n ; i < v.size() ; i++)
    {
        v[i-n] = v[i];
    }
    for(int i = v.size() - n ; i < v.size() ; i++)
    {
        v[i] = tmp[i-(v.size()-n)];
    }
    // print array
    for(int  i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
    // OPTIMAL SOLUTION
    // Uses reverse function
    // No extra space used
    
    reverse(v.begin(),v.begin()+n);
    reverse(v.begin()+n,v.end());
    reverse(v.begin(),v.end());
    
    // print array
    for(int  i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
    return 0;
}
