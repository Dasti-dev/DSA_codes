#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void print ( vector<int> v )
{
    for(int i = 0 ; i  < v.size() ; i++ )
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

bool sumOne (int i , vector<int> v , vector<int> arr , int n , int tar , int sum )
{
    if( i >= n)
    {
        if( sum == tar )
        {
            print (arr);
            return true;
        }
        return false;
    }
    // Take
    arr.push_back(v[i]);
    sum += v[i];
    if( sumOne(i+1,v,arr,n,tar,sum) == true)
    {
        return true;
    }
    ;
    // Not take
    arr.pop_back();
    sum -= v[i];
    if( sumOne(i+1,v,arr,n,tar,sum) == true)
    {
        return true;
    }
    return false;
}

void sumAll (int i , vector<int> v , vector<int> arr , int n , int tar , int sum )
{
    if( i >= n)
    {
        if( sum == tar )
        {
            print (arr);
        }
        return ;
    }
    // Take
    arr.push_back(v[i]);
    sum += v[i];
    sumAll(i+1,v,arr,n,tar,sum);
    
    // Not take
    arr.pop_back();
    sum -= v[i];
    sumAll(i+1,v,arr,n,tar,sum);
}

int sumCount (int i , vector<int> v , vector<int> arr , int n , int tar , int sum )
{
    if( i >= n)
    {
        if( sum == tar )
        {
            // print (arr);
            return 1;
        }
        return 0;
    }
    // Take
    arr.push_back(v[i]);
    sum += v[i];
    int l = sumCount(i+1,v,arr,n,tar,sum);
    
    // Not take
    arr.pop_back();
    sum -= v[i];
    int r = sumCount(i+1,v,arr,n,tar,sum);
    
    return l+r;
}

int main() {
    
    vector<int> v = {1,2,1};
    int target = 2;
    
    cout << "All subsequence with sum 2 : " << endl;
    sumAll (0,v,{},v.size(),target,0);
    cout << "First subsequence with sum 2 : " << endl;
    sumOne (0,v,{},v.size(),target,0);
    cout << "Number of subsequence with sum 2 : " << endl;
    int total = sumCount (0,v,{},v.size(),target,0);
    cout << total << endl;
    return 0;
}
