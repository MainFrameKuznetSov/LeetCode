class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n=lcp.size();
        string ans(n,'0');
        char pre='a';
        for(int i=0;i<n;++i)
        {
            if(ans[i]!='0')
                continue;
            if(pre>'z')
                return "";
            for(int j=i;j<n;++j)
            {
                if(lcp[i][j])
                    ans[j]=pre;
            }
            ++pre;
        }
        vector<vector<int>>table(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;--i)
        {
            for(int j=n-1;j>=0;--j)
            {
                if(ans[i]==ans[j])
                    table[i][j]=table[i+1][j+1]+1;
                else
                    table[i][j]=0;
                if(table[i][j]!=lcp[i][j])
                    return "";
            }
        }
        return ans;
    }
};