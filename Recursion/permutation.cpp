#include<iostream>
#include<vector>
using namespace std;

class Solution {
    private:
    void solve(vector<int> nums,vector<vector<int>>& ans,int index)
    {
        if(index>=nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[index],nums[i]);
            solve(nums,ans,index+1);
            // backtracking
            swap(nums[i],nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index=0;
        solve(nums,ans,index);
        return ans;
        
    }
};


int main()
{
    vector<int> arr={1,2,3};
    Solution o;
   vector<vector<int>> arr1 = o.permute(arr);
   for(auto i:arr1)
   {
    cout<<i<<" ";
   }
   return 0;
}