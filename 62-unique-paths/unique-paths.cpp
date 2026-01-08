class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>pre(n,1);
        for(int i=1;i<n;++i)
            pre[i]=1;
        for(int i=1;i<m;++i)
        {
            // dp[i][0]=1;
            vector<int>cur(n,1);
            for(int j=0;j<n;++j)
            {
                int up=pre[j],left=0;
                if(j>=1)
                    left=cur[j-1];
                cur[j]=up+left;
            }
            swap(pre,cur);
        }
        return pre[n-1];
    }
};