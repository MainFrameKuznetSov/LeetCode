class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size(),pre=0,cur=1,ans=0;
        for(int i=1;i<n;++i)
        {
            if(nums[i]>nums[i-1])
                ++cur;
            else
            {
                pre=cur;
                cur=1;
            }
            ans=max(ans,cur/2);
            ans=max(ans,min(pre,cur));
        }
        return ans;
    }
};