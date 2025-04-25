class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        long long ans=0,temp=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i:nums)
        {
            if(i%mod==k)
                ++temp;
            int rem=temp%mod,extra=(rem-k+mod)%mod;
            ans+=mp[extra];
            ++mp[rem];
        }
        return ans;
    }
};