class Solution {
public:

    void dfs(int i,int j,int n,int m,int pre,int color,vector<vector<bool>>&vis,vector<vector<int>>&ans)
    {
        vis[i][j]=1;
        ans[i][j]=color;
        int di[]={-1,0,1,0};
        int dj[]={0,1,0,-1};
        for(int k=0;k<4;++k)
        {
            int ni=i+di[k],nj=j+dj[k];
            if(ni>=0 && ni<n && nj>=0 && nj<m && ans[ni][nj]==pre && !vis[ni][nj])
                dfs(ni,nj,n,m,pre,color,vis,ans);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(),m=image[0].size();
        vector<vector<int>>ans=image;
        int pre=image[sr][sc];
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        if(pre!=color)
            dfs(sr,sc,n,m,pre,color,vis,ans);
        return ans;
    }
};