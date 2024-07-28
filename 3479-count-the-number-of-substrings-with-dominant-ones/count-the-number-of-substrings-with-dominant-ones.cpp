class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size(),ans=0;
        vector<int>v(n+1,0);
        int i=1;
        for(char ch:s) 
        {
            if (ch=='0')
                ++v[i];
            v[i]+=v[i - 1];
            ++i;
        }
        vector<int> mp;
        int val=0;
        for (int i=0;i<=n;++i) 
        {
            if(v[i]==val) 
            {
                mp.push_back(i);
                ++val;
            }
        }
        mp.push_back(n+1);
        for(i=1;i<=n;++i) 
        {
            for (int j=0;j<200 && j<=v[i];++j)
                ans+=max(0,min(i-j*(j+1)+(j!= 0),mp[v[i]-j+1])-mp[v[i]-j]);
        }
        return ans;
    }
};