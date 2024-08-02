class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ans=INT_MAX,c0=0,c1=0,n=nums.size();
        for(auto iter:nums)
        {
            if(iter==1)
                ++c1;
        }
        for(int i=0;i<c1;++i)
        {
            if(nums[i]==0)
                ++c0;
        }
        ans=min(c0,ans);
        //Circular
        for(int i=c1;i<n*2;++i)
        {
            if(nums[i%n]==0)
                ++c0;
            if(nums[(i-c1)%n]==0)
                --c0;
            ans=min(ans,c0);
        }
        return ans;
    }
};