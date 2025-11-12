class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<int>pre(n,0);
        for(int i=0;i<n;++i)
            pre[i]=matrix[0][i];
        for(int i=1;i<n;++i)
        {
            vector<int>cur(n,0);
            for(int j=0;j<n;++j)
            {
                cur[j]=pre[j];
                if(j-1>=0)
                    cur[j]=min(cur[j],pre[j-1]);
                if(j+1<n)
                    cur[j]=min(cur[j],pre[j+1]);
                cur[j]+=matrix[i][j];
            }
            pre=cur;
            cur.clear();
        }
        int ans=INT_MAX;
        for(int i=0;i<n;++i)
            ans=min(ans,pre[i]);
        return ans;
    }
};