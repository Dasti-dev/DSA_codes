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
    
    vector<vector<int>> v = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    
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

    
    // Better solution
    // O(n2) 
    
    // ###############################################################
    
    // print an array
    // for(int i = 0 ; i < v.size() ; i++)
    // {
    //     for(int j = 0 ; j < v[i].size() ; j++)
    //     {
    //         cout << v[i][j] << "  ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    
    
    // Optimal solution
    // O(3n) and O(n) if set takes O(1)
    
    
    int left = 0 ; 
    int right = m-1;
    int top = 0;
    int bottom = n-1;
    
    vector<int> sol;
    
    while( top <= bottom && right >= left )
    {
        for(int i = left ; i <= right ; i++)
        {
            sol.push_back(v[top][i]);
        }
        top++;
        for(int i = top ; i <= bottom ; i++)
        {
            sol.push_back(v[i][right]);
        }
        right--;
        if( top <= bottom ){
            for(int i = right ; i >= left ; i--)
            {
                sol.push_back(v[bottom][i]);
            }
            bottom--;
        }
        if( left <= right ){
            for(int i = bottom ; i >= top ; i--)
            {
                sol.push_back(v[i][left]);
            }
            left++;
        }
    }
    
    for(int i = 0 ; i < sol.size() ; i++)
    {
        cout << sol[i] << " ";
    }
    cout << endl; 
    
    return 0;
}
