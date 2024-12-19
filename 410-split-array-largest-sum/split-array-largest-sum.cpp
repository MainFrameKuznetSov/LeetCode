class Solution {
public:

    int BSA(int mid,vector<int>&nums,int k)
    {
        int ptr=0,cnt=0;
        for(int i=0;i<nums.size();++i)
        {
            if(ptr>=nums[i])
                ptr-=nums[i];
            else
            {
                ++cnt;
                ptr=mid-nums[i];
            }
            if(cnt>k)
                return 0;
        }
        return (k>=cnt);
    }

    int splitArray(vector<int>& nums, int k) {
        int l=0,r=0,ans=0;
        for(auto it:nums)
        {
            l=max(l,it);
            r+=it;
        }
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(BSA(mid,nums,k))
            {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};