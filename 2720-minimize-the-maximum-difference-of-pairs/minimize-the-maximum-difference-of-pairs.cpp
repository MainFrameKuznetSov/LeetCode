class Solution {
public:

    int helper(int mid,vector<int>&nums)
    {
        int cnt=0;
        for(int i=1;i<nums.size();++i)
        {
            if(mid+nums[i-1]>=nums[i])
            {
                ++cnt;
                ++i;
            }
        }
        return cnt;
    }

    int minimizeMax(vector<int>& nums, int p) {
        if(p==0)
            return 0;
        sort(nums.begin(),nums.end());
        int n=nums.size(),left=0,right=nums[n-1]-nums[0];
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(helper(mid,nums)>=p)
                right=mid;
            else
                left=mid+1;
        }
        return left;
    }
};