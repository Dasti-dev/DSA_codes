#include <vector>
#include <climits>
#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_set>


using namespace std;

bool ls( int tar , vector<int> v )
{
    for(int i = 0 ; i < v.size() ; i++)
    {
        if(tar == v[i])
        {
            return true;
        }
    }
    return false;
}
void markRow(int i , vector<vector<int>> &v)
{
    for(int j = 0 ; j < v[i].size() ; j++)
    {
        if(v[i][j] != 0)
        {
            v[i][j] = -1;
        }
    }
}
void markCol(int i , vector<vector<int>> &v)
{
    for(int j = 0 ; j < v.size() ; j++)
    {
        for(int k = 0 ; k < v[j].size() ; k++)
        {
            if(v[j][i] == 1)
            {
                v[j][i] = -1;
            }
        }
    }
}

int main() {
    
    // rotate by 90 deg
    
    vector<vector<int>> v = {{0,1,2,0},{3,4,5,2},{1,3,1,5},{9,8,7,6}};
    
    // print an array
    for(int i = 0 ; i < v.size() ; i++)
    {
        for(int j = 0 ; j < v[i].size() ; j++)
        {
            cout << v[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
    
    int m = v[0].size();
    int n = v.size();
    
    // brute force
    // O(n2) O(n2)
    vector<int> row(n,0);
    vector<vector<int>> ans(m,row);
    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            ans[j][n-i-1] = v[i][j];
        }
    }
    
    
    // print an array
    for(int i = 0 ; i < ans.size() ; i++)
    {
        for(int j = 0 ; j < ans[i].size() ; j++)
        {
            cout << ans[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
   
    
    // Better solution
    // O(n2) 
    
    // ###############################################################
    
    // print an array
    for(int i = 0 ; i < v.size() ; i++)
    {
        for(int j = 0 ; j < v[i].size() ; j++)
        {
            cout << v[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
    
    
    // Optimal solution
    // O(3n) and O(n) if set takes O(1)
    
    // works on symmetric matrix
    
    for(int i = 1 ; i < v.size() ; i++)
    {
        for(int j = 0 ; j < i ; j++)
        {
            swap(v[i][j],v[j][i]);
        }
    }
    
    for(int i = 0 ; i < v.size() ; i++)
    {
        reverse(v[i].begin(),v[i].end());
    }
    
    // print an array
    for(int i = 0 ; i < v.size() ; i++)
    {
        for(int j = 0 ; j < v[i].size() ; j++)
        {
            cout << v[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
    
    int flag = 0;
    for(int i = 0 ; i < v.size() ; i++)
    {
        for(int j = 0; j < v[i].size() ; j++)
        {
            if(v[i][j] != ans[i][j])
            {
                flag = 1;
                break;
            }
        }
    }
    if(flag == 1)
    {
        cout << "unsuccessful" << endl;
    }
    else
    {
        cout << "rotated successfully" << endl;
    }
    
    return 0;
}
