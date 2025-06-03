class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n=status.size(),ans=0;
        queue<int>q;
        vector<bool>vis(n,0);
        for(int it:initialBoxes)
        {
            if(status[it])
                q.push(it);
            else
                vis[it]=1;
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans+=candies[node];
            for(int it:keys[node])
            {
                if(!status[it] && vis[it])
                    q.push(it);
                status[it]=1;
            }
            for(int it:containedBoxes[node])
            {
                if(status[it])
                    q.push(it);
                else
                    vis[it]=1;
            }
        }
        return ans;
    }
};