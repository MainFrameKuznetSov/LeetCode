#define ll long long

class Solution{
public:
    vector<vector<int>>graph;
    vector<int>present;
    vector<int>future;
    int budget;
    vector<vector<vector<ll>>>dp;

    void update(vector<ll>&curr,vector<ll>&child)
    {
        vector<ll>temp(budget+1,0);
        for(int i=0;i<=budget;++i)
        {
            for(int j=0;j<=i;++j)
                temp[i]=max(temp[i],curr[j]+child[i-j]);
        }
        curr=temp;
    }

    void dfs(int node)
    {
        for(int it:graph[node])
            dfs(it);

        for(int i=0;i<=1;++i)
        {
            if(node==0 && i==1) 
                continue;

            int price=present[node];
            if(i) 
                price/=2;

            vector<ll>notTake(budget + 1, 0);
            for(int it:graph[node])
                update(notTake,dp[it][0]);

            vector<ll>take(budget+1,0);
            if(price<=budget)
            {
                vector<ll>vec(budget+1,0);
                for(int it:graph[node])
                    update(vec,dp[it][1]);
                
                ll profit=future[node]-price;
                for(int j=price;j<=budget;++j)
                    take[j]=vec[j-price]+profit;
            }

            for(int j=0;j<=budget;++j)
                dp[node][i][j]=max(take[j],notTake[j]);
        }
    }
    
    int maxProfit(int n, vector<int>& present, vector<int>& future,
                  vector<vector<int>>& edges, int budget)
    {
        this->present=present;
        this->future=future;
        this->budget=budget;

        graph.resize(n);
        for(auto it:edges)
            graph[it[0]-1].push_back(it[1]-1);

        dp=vector<vector<vector<ll>>>
             (n,vector<vector<ll>>(2,vector<ll>(budget+1,0)));
        dfs(0);

        ll ans=0;
        for(int i=0;i<=budget;++i)
            ans=max(ans,dp[0][0][i]);
        return (int)ans;
    }
};
