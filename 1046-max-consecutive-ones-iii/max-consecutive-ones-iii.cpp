class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size(),left=0,maxLen=0,cntZero=0;
        for(int right=0;right<n;++right)
        {
            if(nums[right]==0)
                ++cntZero;
            while(cntZero>k)
            {
                if(nums[left++]==0)
                    --cntZero;
            }
            maxLen=max(maxLen,right-left+1);
        }
        return maxLen;
    }
};