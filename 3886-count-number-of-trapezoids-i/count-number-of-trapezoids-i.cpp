#define MOD (int)(1e9+7)
#define ll long long

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int>mp;
        ll ans=0,temp=0;
        for(auto it:points)
            ++mp[it[1]];
        for(auto it:mp)
        {
            ll cnt=(ll)it.second*(it.second-1)/2;
            ans=(ans+(cnt*temp)%MOD)%MOD;
            temp=(temp+cnt)%MOD;
        }
        return ans%MOD;
    }
};