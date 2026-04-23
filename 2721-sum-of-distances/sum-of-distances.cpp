#define ll long long

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        vector<ll>ans(n);
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;++i)
            mp[nums[i]].push_back(i);
        for(auto it:mp)
        {
            auto vec=it.second;
            int sz=vec.size();
            ll tot=0,fpart=0;
            for(int i:vec)
                tot+=i;
            for(int i=0;i<sz;++i)
            {
                ll spart=tot-fpart-vec[i];
                ll f=1LL*vec[i]*i-fpart,s=spart-1LL*vec[i]*(sz-i-1);
                ans[vec[i]]=f+s;
                fpart+=vec[i];
            }
        }
        return ans;
    }
};