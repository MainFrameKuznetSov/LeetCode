class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size(),left=k,right=k,mn=nums[k],ans=nums[k];
        while(left>0 || right<n-1)
        {
            if(left==0 || (nums[right+1]>nums[left-1] && right<n-1))
                ++right;
            else
                --left;
            mn=min(mn,min(nums[left],nums[right]));
            ans=max(ans,mn*(right-left+1));
        }
        return ans;
    }
};