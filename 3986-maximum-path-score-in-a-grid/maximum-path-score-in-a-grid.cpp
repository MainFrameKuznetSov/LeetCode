#define NINF (int)-1e9

class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>pre(n,vector<int>(k+1,NINF));
        for(int i=0;i<m;++i)
        {
            vector<vector<int>>cur(n,vector<int>(k+1,NINF));
            for(int j=0;j<n;++j)
            {
                for(int l=0;l<=k;++l)
                    cur[j][l]=NINF;
            }
            for(int j=0;j<n;++j)
            {
                int cs=grid[i][j]==0?0:1,sc=grid[i][j];
                if(!i && !j)
                {
                    if(cs<=k)
                        cur[0][cs]=sc;
                    continue;
                }
                if(i)
                {
                    for(int l=0;l<=k;++l)
                    {
                        int ini=pre[j][l];
                        if(ini==NINF)
                            continue;
                        int fin=l+cs;
                        if(fin<=k)
                            cur[j][fin]=max(cur[j][fin],sc+ini);
                    }
                }
                if(j)
                {
                    for(int l=0;l<=k;++l)
                    {
                        int ini=cur[j-1][l];
                        if(ini==NINF)
                            continue;
                        int fin=l+cs;
                        if(fin<=k)
                            cur[j][fin]=max(cur[j][fin],sc+ini);
                    }
                }
            }
            pre=cur;
            cur.clear();
        }
        int ans=NINF;
        for(int i=0;i<=k;++i)
            ans=max(ans,pre[n-1][i]);
        return ans==NINF?-1:ans;
    }
};