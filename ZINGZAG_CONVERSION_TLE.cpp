// ZIGZAG CONVERSION TLE
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
string ans = "";
int numRows = 5;
string s = "PAYPALISHIRING";
        // vector<vector<char>> str;
        
        vector<int> loc;
        vector<vector<int>> gap;
        gap.push_back({2*numRows-3,2*numRows-3});
        int counter;
        if(numRows%2 == 0)
        {
            counter = (numRows-1)/2;
        }
        else
        {
            counter = numRows/2;
        }
        for(int i = 1 ; i < counter + 1 ; i++ )
        {
            gap.push_back({2*numRows-3-2*i,(2*numRows-4)-(2*numRows-3-2*i)});
        }
        if(gap.size() % 2 != 0)
        {
            for( int i = gap.size()-1 ; i >= 0 ; i-- )
            {
                gap.push_back(gap[i]);
            }
        }
        else
        {
            for( int i = gap.size()-2 ; i >= 0 ; i-- )
            {
                gap.push_back(gap[i]);
            }
        }
        for(int i = 0 ; i < gap.size() ; i++)
        {
            for(int j = 0 ; j < gap[i].size() ; j++)
            {
                gap[i][j]++;
            }
        }
     
        int j = 0;
        for( int i = 0 ; i < gap.size() ; i++ )
        {
            int p = i;
            loc.push_back(p);
            while(p<s.size())
            {
                if(p+gap[j][1]<s.size())
                {
                    loc.push_back(p+gap[j][1]);
                }
                else
                {
                    break;
                }
                p = p + gap[j][1];
                int tmp = gap[j][0];
                gap[j][0] = gap[j][1];
                gap[j][1] = tmp;
            }
            j++;
        }
        for(int i = 0 ; i < loc.size() ; i++)
        {
            ans.push_back(s[loc[i]]);
        }
        cout<<ans<<endl;
        cout<<"PINALSIGYAHRPI";

        
    return 0;
}
