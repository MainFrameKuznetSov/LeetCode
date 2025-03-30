class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int,int>mp;
        int n=s.size();
        vector<int>ans;
        for(int i=0;i<n;++i)
            mp[s[i]]=i;
        int l=0,r=0;
        for(int i=0;i<n;++i)
        {
            r=max(r,mp[s[i]]);
            if(i==r)
            {
                ans.push_back(r-l+1);
                l=i+1;
            }
        }
        return ans;
    }
};