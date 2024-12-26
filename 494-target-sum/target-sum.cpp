class Solution {
public:

    int ans;

    int findTargetSumWays(vector<int>& nums, int target) {
        ans=0;
        recur(nums,0,0,target);
        return ans;
    }

    void recur(vector<int>&nums,int ind,int sum,int target)
    {
        if(ind==nums.size())
        {
            if(sum==target)
                ++ans;
        }
        else
        {
            recur(nums,ind+1,sum+nums[ind],target);
            recur(nums,ind+1,sum-nums[ind],target);
        }
    }

};