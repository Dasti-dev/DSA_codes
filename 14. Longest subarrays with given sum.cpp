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
    
    vector<int> v = {1,2,3,1,1,1,1,3,3};
    int target = 3;
    
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
    
    // BETTER SOLUTION 
    // Hashing
    // TC -> O(Nlogn)
    // SC -> O(N)
    map<long long,int> hash;
    long long int sum1 = 0;
    int len1 = 0;
    for(int i = 0 ; i < v.size() ; i++)
    {
        sum1 = sum1 + v[i];
        if(sum1 ==  target)
        {
            len1 = max(len1,i+1);
        }
        int rem = sum1 - target;
        if(hash.find(rem) != hash.end())
        {
            len1 = max(len1,(i-hash[rem]));
        }
        if(hash.find(sum1) == hash.end())
        {
            hash[sum1] = i;
        }
        
    }
    cout << len1 << endl;
    // OPTIMAL SOLUTION
    // Runs for 0 and positive only
    // Greedy and 2 pointer
    // TC -> O(2N)
    // SC -> O(1)
    int left = 0;
    int right = 0;
    int long long sum = v[0];
    int len = 0;
    while(right < v.size())
    {
        while(left <= right && sum > target)
        {
            sum = sum - v[left];
            left++;
        }
        if(sum == target)
        {
            len = max(len,right-left+1);
        }
        right++;
        if(right < v.size())
            sum = sum + v[right];
    }
    cout << len << endl;
    
    return 0;
}
