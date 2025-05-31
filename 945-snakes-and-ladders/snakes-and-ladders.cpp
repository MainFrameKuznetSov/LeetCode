class Solution {
public:

    pair<int,int> helper(int n,int add)
    {
        int R=n-1-((add-1)/n),C=(add-1)%n;
        if(n%2==R%2)
            C=(n-1)-C;
        return {R,C};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size(),steps=0;
        queue<int>q;
        vector<vector<bool>>vis(n,vector<bool>(n,0));
        vis[n-1][0]=1;
        q.push(1);
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int node=q.front();
                q.pop();
                if(node==n*n)
                    return steps;
                for(int i=1;i<=6;++i)
                {
                    int val=node+i;
                    if(val>n*n)
                        break;
                    auto coord=helper(n,val);
                    int r=coord.first,c=coord.second;
                    if(vis[r][c])
                        continue;
                    vis[r][c]=1;
                    if(board[r][c]==-1)
                        q.push(val);
                    else
                        q.push(board[r][c]);
                }
            }
            ++steps;
        }
        return -1;
    }
};