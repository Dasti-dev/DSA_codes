class Solution {
public:

    void csum (int i , vector<int> &arr , int target , vector<int> &v , vector<vector<int>> &ans)
    {
        if(i == arr.size())
        {
            if(target == 0)
            {
                ans.push_back(v);
            }
            return;
        }
        if(arr[i] <= target)
        {
            v.push_back(arr[i]);
            csum (i,arr,target-arr[i],v,ans);
            v.pop_back();
        }
        csum(i+1,arr,target,v,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds ;
        vector<vector<int>> ans ;
        csum(0,candidates,target,ds,ans);
        return ans;
    }
};
