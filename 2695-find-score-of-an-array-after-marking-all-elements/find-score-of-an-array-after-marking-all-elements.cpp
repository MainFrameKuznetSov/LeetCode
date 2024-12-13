class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long n=nums.size(),ans=0;
        int l,r=0;
        while(r<n)
        {
            l=r;
            while(r<n-1 && nums[r]>nums[r+1])
                ++r;
            for(int i=r;i>=l;i-=2)
                ans+=nums[i];
            r+=2;
        }
        return ans;
    }
};