#include<iostream>
#include<vector>
using namespace std;


class Solution {
private:
    void solve(vector<int> nums,vector<int>ouput ,int index,vector<vector<int> >& ans)
    {
        if(index>=nums.size())
        {
            ans.push_back(ouput);
            return;
        }

        // exclude
        solve(nums,ouput,index+1,ans);

        // include
        ouput.push_back(nums[index]);
        solve(nums,ouput,index+1,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int>ouput;
        int index = 0;
        // solve(nums,ans,index,ouput);
        solve(nums,ouput,index,ans);
        return ans;
        
    }
};