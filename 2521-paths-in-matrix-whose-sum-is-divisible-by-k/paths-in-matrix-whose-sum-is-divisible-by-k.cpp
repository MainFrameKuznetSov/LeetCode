#define MOD 1000000007

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>pre(m,vector<int>(k,0));
        for(int i=0;i<n;++i)
        {
            vector<vector<int>>cur(m,vector<int>(k,0));
            for(int j=0;j<m;++j)
            {
                if(i==0 && j==0)
                {
                    cur[0][grid[0][0]%k]=1;
                    continue;
                }
                for(int rem=0;rem<k;++rem)
                {
                    int nrem=(rem+grid[i][j])%k;
                    if(i)
                        cur[j][nrem]=(cur[j][nrem]+pre[j][rem])%MOD;
                    if(j)
                        cur[j][nrem]=(cur[j][nrem]+cur[j-1][rem])%MOD;
                }
            }
            swap(pre,cur);
        }
        return pre[m-1][0];
    }
};