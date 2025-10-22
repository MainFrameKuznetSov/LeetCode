#define F first
#define S second
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int opt) {
        int n=nums.size();
        map<int,int>mp;
        vector<pair<int,int>>pr;
        set<int>st;
        for(int it:nums)
        {
            ++mp[it];
            st.insert(it);
        }
        for(int it:nums)
        {
            pr.push_back({it-k,1});
            st.insert(it-k);
            pr.push_back({it+k+1,-1});
            st.insert(it+k+1);
        }

        sort(pr.begin(),pr.end());

        int ind=0,com=0,ans=0,cnt=0,p=pr.size();
        for(int it:st)
        {
            while(ind<p && pr[ind].F<=it)
            {
                com+=pr[ind].S;
                ++ind;
            }
            if(mp.find(it)!=mp.end())
                cnt=mp[it];
            else
                cnt=0;
            ans=max(ans,cnt+min(com-cnt,opt));
        }
        return ans;
    }
};