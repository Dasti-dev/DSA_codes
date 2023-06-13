#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <bit>
#include <map>
#include <climits>

using namespace std;

int main() {
    
    // vector<int> v = {1,2,3,4,5,6,7,8,10,11};
    // vector<int> v = {0,0,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0};
    
    // vector<int> v2 = {6,28,8,94,53,6,74,05,0,2,04};
    
    vector<int> v = {-2,-3,4,-1,-2,1,5,-3};
    
    // sort(v1.begin(),v1.end());
    // sort(v2.begin(),v2.end());
    // print array
    for(int  i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
    // BRUTE FORCE SOLUTION
    // esists
    
    // BETTER SOLUTION 
    // Hashing
    // TC -> O(Nlogn)
    // SC -> O(N)
    
    // OPTIMAL SOLUTION
    // KADANE S ALGORITHM
    // TC -> O(N)
    // SC -> O(1)
    int news = -1;
    int start = -1;
    int end = -1;
    int sum = 0;
    int maxi = INT_MIN;
    for(int i = 0 ; i < v.size() ; i++)
    {
        if( sum  == 0)
        {
            news = i
        }
        sum += v[i];
        if( sum > maxi )
        {
            maxi = sum;
            start = news;
            end = i;
        }
        if( sum < 0 )
        {
            sum = 0 ;
        }
        
    }
    if(sum < 0)
    {
        cout << "sum is 0" << endl;
    }
    else 
    {
        cout << "sum is " << maxi << endl;
    }
    
    return 0;
}
