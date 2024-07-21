class Solution {
private:
    vector<int> TopoSort(int k, vector<vector<int>>& adj)
    {
        vector<int>indegree(k+1,0);
        for(int i=1;i<=k;++i)
        {
            for(auto iter:adj[i])
                ++indegree[iter];
        }

        queue<int>q;
        vector<int>vis(k+1, 0);
        for(int i=1;i<=k;++i)
        {
            if(indegree[i]==0)
                q.push(i);
        }

        vector<int> ans;
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                int node=q.front();
                q.pop();
                vis[node]=true;
                ans.push_back(node);
                for(auto iter:adj[node])
                {
                    if(!vis[iter])
                    {
                        --indegree[iter];
                        if(indegree[iter]==0) 
                            q.push(iter);
                    }
                }
            }
        }

        vector<int>notTopo;
        for(int i=1;i<=k;++i) 
        {
            if(indegree[i]!=0) 
                return notTopo;
        }
        return ans;
    }

    void fillTopoArray(int k, vector<int>& arr)
    {
        unordered_map<int,bool>mp;
        for(auto iter:arr) 
            mp[iter]=1;
        for(int i=1;i<=k;++i)
        {
            if(!mp[i]) 
                arr.push_back(i);
        }
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) 
    {
        int n=rowConditions.size(),m=colConditions.size();
        vector<vector<int>>adjRow(k+1),adjCol(k+1);

        for(auto iter:rowConditions)
            adjRow[iter[0]].push_back(iter[1]);
        
        for(auto iter:colConditions)
            adjCol[iter[0]].push_back(iter[1]);

        vector<int>rTopo=TopoSort(k,adjRow);
        vector<int>cTopo=TopoSort(k,adjCol);
        vector<vector<int>> ans;

        if(rTopo.size()==0 || cTopo.size()==0)
            return ans;
        

        fillTopoArray(k,rTopo);
        fillTopoArray(k,cTopo);

        unordered_map<int,int>mp;
        for(int j=0;j<k;++j)
            mp[cTopo[j]]=j;

        ans=vector<vector<int>>(k,vector<int>(k,0));
        for(int i=0;i<k;++i)
            ans[i][mp[rTopo[i]]]=rTopo[i];
        
        return ans;        
    }
};