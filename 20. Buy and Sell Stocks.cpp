#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <bit>
#include <map>
#include <climits>

using namespace std;

int main() {
    
    vector<int> v = {7,1,5,3,6,5};
    
    // sort(v1.begin(),v1.end());
    // sort(v2.begin(),v2.end());
    // print array
    for(int  i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
    // BRUTE FORCE SOLUTION
    
    // BETTER SOLUTION 
   
    // OPTIMAL SOLUTION
    // TC -> O(N)
    // SC -> O(1)
    int buy = v[0];
    int buyd = 0;
    int profit = 0;
    int selld = -1;
    for(int i = 0 ; i < v.size() ; i++)
    {
        if(v[i]<buy)
        {
            buy = v[i];
            buyd = i;
        }
        if(v[i]-buy > profit)
        {
            profit = v[i]-buy;
            selld = i;
        }
    }
    
    cout << "buy on " << buyd << " at " << buy << endl;
    cout << "sell on " << selld << " at " << v[selld] << endl;
    cout << "you get max profit of " << profit << endl;
    
    return 0;
}
