class Solution {
public:

    vector<pair<int,int>>dir={{-1,0},{0,1},{1,0},{0,-1}};
    int n,m;

    void dfs(int i,int j,vector<vector<bool>>&ocean,vector<vector<int>>&heights)
    {
        ocean[i][j]=true;
        for(int k=0;k<4;++k)
        {
            int ni=i+dir[k].first,nj=j+dir[k].second;
            if(ni>=0 && ni<n && nj>=0 && nj<m && !ocean[ni][nj] &&
                heights[ni][nj]>=heights[i][j])
                dfs(ni,nj,ocean,heights);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n=heights.size();
        m=heights[0].size();
        vector<vector<bool>>pacific(n,vector<bool>(m,false)),
                            atlantic(n,vector<bool>(m,false));
        for(int i=0;i<m;++i)
        {
            dfs(0,i,pacific,heights);
            dfs(n-1,i,atlantic,heights);
        }
        for(int i=0;i<n;++i)
        {
            dfs(i,0,pacific,heights);
            dfs(i,m-1,atlantic,heights);
        }

        vector<vector<int>>ans;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};