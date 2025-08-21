#define OFF 10000

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>freq(1e5+1,0),ans;
        int mn=INT_MAX,mx=INT_MIN;
        for(int i:nums)
        {
            mn=min(mn,i);
            mx=max(mx,i);
            ++freq[i+OFF];
        }
        vector<pair<int,int>>pr;
        for(int i=mn;i<=mx;++i)
        {
            if(freq[i+OFF]>0)
                pr.push_back({i,freq[i+OFF]});
        }
        sort(pr.begin(),pr.end(),[&](pair<int,int>a,pair<int,int>b)
        {
            if(a.second>b.second)
                return true;
            return false;
        });
        for(int i=0;i<k;++i)
            ans.push_back(pr[i].first);
        return ans;
    }
};