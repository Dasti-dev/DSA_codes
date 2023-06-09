#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    vector<int> v = {3, 5, 7, 9, 11, 13, 17, 19, 22, 14, 9 ,4};
    // ONLY SOLUTION
    for(int i = 0 ; i < v.size()-1 ; i++)
    {
        if(v[i+1] < v[i])
        {
            cout << "not sorted" << endl;
            break;
        }
        
    }
    return 0;
}
