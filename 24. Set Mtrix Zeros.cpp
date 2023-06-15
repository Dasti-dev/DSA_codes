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
    
    // longest consecutive sequence
    
    vector<vector<int>> v = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    
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
    
    // brute force
    // O(n3)
    
    for(int i = 0 ; i < v.size() ; i++)
    {
        for(int j = 0 ; j < v[i].size() ; j++)
        {
            if(v[i][j] == 0)
            {
                markRow(i , v);
                markCol(j , v);
            }
        }
    }
    
    for(int i = 0 ; i < v.size() ; i++)
    {
        for(int j = 0 ; j < v[i].size() ; j++)
        {
            if(v[i][j] == -1)
            {
                v[i][j] = 0;
            }
        }
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
   
    
    // Better solution
    // O(n2) 
    
    vector<int> col(v[0].size(),0);
    vector<int> row(v.size(),0);
    
    for(int i = 0 ; i < v.size() ; i++)
    {
        for(int j = 0 ; j < v[i].size() ; j++)
        {
            if(v[i][j] == 0)
            {
                col[j] = 1;
                row[i] = 1;
            }
        }
    }
    for(int i = 0 ; i < v.size() ; i++)
    {
        for(int j = 0 ; j < v[i].size() ; j++)
        {
            if(col[j] == 1 || row[i] == 1)
            {
                v[i][j] = 0;
            }
        }
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
    
    
    // Optimal solution
    // O(3n) and O(n) if set takes O(1)
    
    int col0 = 1;
    for(int i = 0 ; i < v.size() ; i++)
    {
        for(int j = 0 ; j < v[i].size() ; j++)
        {
            if(v[i][j] == 0)
            {
                if(j!=0)
                    v[0][j] = 0;
                else
                    col0 = 0
                v[i][0] = 0;
            }
        }
    }
    
    for(int i = 1 ; i < v.size() ; i++)
    {
        for(int j = 1 ; j < v[i].size() ; j++)
        {
            if(v[0][j] == 0 || v[i][0] == 0)
            {
                v[i][j] = 0;
            }
        }
    }
    
    if(v[0][0] == 0)
    {
        for(int j = 0 ; j < v[0].size() ; j++)
        {
            v[0][j] = 0;
        }
    }
    if(col0 == 0)
    {
        for(int i = 0 ; i < v.size() ; i++)
        {
            v[i][0] = 0;
        }
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
    
    return 0;
}
