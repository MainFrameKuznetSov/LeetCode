class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long sum=0,ans=LLONG_MIN;
        unordered_map<int,long long>mp;
        mp[0]=0;
        for(int i=1;i<k;++i)
            mp[i]=LLONG_MAX;
        for(int i=0;i<n;++i)
        {
            sum+=nums[i];
            if(mp[(i+1)%k]!=LLONG_MAX)
                ans=max(ans,sum-mp[(i+1)%k]);
            mp[(i+1)%k]=min(mp[(i+1)%k],sum);
        }
        return ans;
    }
};