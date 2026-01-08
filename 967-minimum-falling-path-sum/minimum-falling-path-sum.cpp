#define INF (int)1e9

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>&grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int>pre(m,0);
        for(int i=0;i<m;++i)
            pre[i]=grid[0][i];
        for(int i=1;i<n;++i)
        {
            vector<int>cur(m,0);
            for(int j=0;j<m;++j)
            {
                int top=pre[j],ld=INF,rd=INF;
                if(j>=1)
                    ld=pre[j-1];
                if(j+1<m)
                    rd=pre[j+1];
                cur[j]=min({top,ld,rd})+grid[i][j];
            }
            swap(pre,cur);
        }
        int ans=INF;
        for(int i:pre)
            ans=min(ans,i);
        return ans;
    }
};