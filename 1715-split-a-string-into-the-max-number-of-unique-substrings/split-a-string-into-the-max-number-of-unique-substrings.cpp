class Solution {
public:
    void recur(int ind,int &n,string &s,unordered_map<string,int>&mp,int &mx)
    {
        if(ind==n)
        {
            int m=mp.size();
            mx=max(mx,m);
            return;
        }
        for(int i=ind;i<n;++i)
        {
            string temp=s.substr(ind,i-ind+1);
            if(mp.find(temp)==mp.end())
            {
                ++mp[temp];
                recur(i+1,n,s,mp,mx);
                --mp[temp];
                if(mp[temp]==0)
                    mp.erase(temp);
            }
        }
    }
    int maxUniqueSplit(string s) {
        unordered_map<string,int>mp;
        int mx=1,n=s.size();
        recur(0,n,s,mp,mx);
        return mx;
    }
};