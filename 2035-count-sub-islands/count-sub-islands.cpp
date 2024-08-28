class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&grid2,vector<pair<int,int>>&temp,int n,int m)
    {
        vis[i][j]=1;
        temp.push_back({i,j});
        int di[]={-1,0,1,0};
        int dj[]={0,1,0,-1};
        for(int k=0;k<4;++k)
        {
            int ni=i+di[k],nj=j+dj[k];
            if(ni>=0 && ni<n && nj>=0 && nj<m && !vis[ni][nj] && grid2[ni][nj]==1)
            {
                temp.push_back({ni,nj});
                dfs(ni,nj,vis,grid2,temp,n,m);
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid2.size(),m=grid2[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<pair<int,int>>>cmp;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            { 
                if(!vis[i][j] && grid2[i][j]==1)
                {
                    vector<pair<int,int>>temp;
                    dfs(i,j,vis,grid2,temp,n,m);
                    if(temp.size()!=0)
                        cmp.push_back(temp);
                }
            }
        }
        /*cout<<cmp.size()<<"\n";
        for(int i=0;i<cmp.size();++i)
        {
            for(int j=0;j<cmp[i].size();++j)
            {
                auto iter=cmp[i][j];
                cout<<"{"<<iter.first<<","<<iter.second<<"}";
            }
            cout<<"\n";
        }*/
        int ans=0;
        for(int i=0;i<cmp.size();++i)
        {
            bool flag=true;
            for(int j=0;j<cmp[i].size();++j)
            {
                auto iter=cmp[i][j];
                if(grid1[iter.first][iter.second]!=1)
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
                ++ans;
        }
        return ans;
    }
};