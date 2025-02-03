class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size(),inc=1,dec=1,ans=1;
        for(int ind=0;ind<n-1;++ind)
        {
            if(nums[ind]>nums[ind+1])
            {
                ++dec;
                inc=1;
            }
            else if(nums[ind]<nums[ind+1])
            {
                ++inc;
                dec=1;
            }
            else
            {
                inc=1;
                dec=1;
            }
            ans=max(ans,max(dec,inc));
        }
        return ans;
        /*
            Overall Time complexity:- O(n)
            Overall Space complexity:- O(1)
        */
    }
};