#define ll long long

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int>mp;
        for(int i:basket1)
            ++mp[i];
        for(int i:basket2)
            --mp[i];

        int mn=INT_MAX;
        vector<int>temp;
        for(auto it:mp)
        {
            if(it.second&1)
                return -1;
            for(int i=0;i<abs(it.second)/2;++i)
                temp.push_back(it.first);
            mn=min(mn,it.first);
        }
        sort(temp.begin(),temp.end());
        ll ans=0;
        for(int i=0;i<temp.size()/2;++i)
            ans+=min(temp[i],mn*2);
        return ans;

    }
};