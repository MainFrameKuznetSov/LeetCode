class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=1,mx=INT_MIN,n=nums.size(),temp=0;
        for(int i=0;i<n;++i)
            mx=max(mx,nums[i]);
        for(int i=0;i<n;++i)
        {
            if(nums[i]==mx)
                ++temp;
            else
            {
                ans=max(ans,temp);
                temp=0;
            }
        }
        return max(ans,temp);
    }
};