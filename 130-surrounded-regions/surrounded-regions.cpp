class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>&board,int n,int m)
    {
        vis[i][j]=1;
        int di[]={-1,0,1,0};
        int dj[]={0,1,0,-1};
        for(int k=0;k<4;++k)
        {
            int ni=i+di[k],nj=j+dj[k];
            if(ni>=0 && ni<n && nj>=0 && nj<m && !vis[ni][nj] && board[ni][nj]=='O')
                dfs(ni,nj,vis,board,n,m);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;++i)
        {
            if(!vis[i][0] && board[i][0]=='O')
                dfs(i,0,vis,board,n,m);
            if(!vis[i][m-1] && board[i][m-1]=='O')
                dfs(i,m-1,vis,board,n,m);
        }
        for(int i=0;i<m;++i)
        {
            if(!vis[0][i] && board[0][i]=='O')
                dfs(0,i,vis,board,n,m);
            if(!vis[n-1][i] && board[n-1][i]=='O')
                dfs(n-1,i,vis,board,n,m);
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(board[i][j]=='O' && !vis[i][j])
                    board[i][j]='X';
            }
        }
    }
};