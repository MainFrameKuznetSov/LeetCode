class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(),m=s2.size(),ans=0;
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        vector<int>pre(m+1,0);
        for(int i=0;i<n;++i)
        {
            vector<int>cur(m+1,0);
            for(int j=0;j<m;++j)
            {
                if(s1[i]==s2[j])
                    cur[j+1]=pre[j]+s1[i];
                else
                    cur[j+1]=max(pre[j+1],cur[j]);
            }
            swap(pre,cur);
        }
        for(char c:s1)
            ans+=(int)c;
        for(char c:s2)
            ans+=(int)c;
        return ans-2*pre[m];
    }
};