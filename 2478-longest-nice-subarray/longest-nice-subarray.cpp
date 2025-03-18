class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size(),left=0,right=left,ans=1;
        int val=0;
        while(right<n)
        {
            while((nums[right]&val)!=0)
            {
                val^=nums[left];
                ++left;
            }
            val|=nums[right];
            ans=max(ans,right-left+1);
            ++right;
        }
        return ans;
    }
};