#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void rev (int i , vector<int> &arr , int n)
{
    if(i > n/2)
    {
        return;
    }
    swap(arr[i],arr[n-i-1]);
    rev(i+1,arr,n);
}

bool palindrome (int i , string &s , int n)
{
    if(i >= n/2)
    {
        return true;
    }
    if(s[i] != s[n-i-1])
    {
        return false;
    }
    palindrome(i+1 , s , n);
}

int main() {
    
    vector<int> v = {1,2,3,4,5,6,7,8};
    
    // print array
    for(int i = 0 ;  i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
    rev (0,v,v.size());
    
    // print array
    for(int i = 0 ;  i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
    string s = "M A D A M";
    
    bool flag = palindrome(0,s,s.size());
    
    if(flag == true)
    {
        cout << "String is a palindrome" << endl;
    }
    else 
    {
        cout << "String is not a palindrome" << endl;
    }
    
    
    return 0;
}
