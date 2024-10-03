class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum=0;
        for(int it:nums)
            sum+=it;
        int rem=sum%p;
        if(rem==0)
            return 0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        long long psum=0;
        int ans=nums.size();
        for(int i=0;i<nums.size();++i)
        {
            psum+=nums[i];
            int mod=psum%p;
            int diff=(mod-rem+p)%p;
            if(mp.find(diff)!=mp.end())
                ans=min(ans,i-mp[diff]);
            mp[mod]=i;
        }
        return ans==nums.size()?-1:ans;
    }
};