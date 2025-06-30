class Solution {
public:

    double price(int src,int dest,vector<vector<pair<int,double>>>&adj)
    {
        int n=adj.size();
        vector<double>cost(n,-1.0);
        cost[src]=1.0;
        set<pair<double,int>>st;
        st.insert({1.0,src});
        while(!st.empty())
        {
            auto top=*st.begin();
            st.erase(top);
            double rate=top.first;
            int node=top.second;
            if(node==dest)
                return rate;
            for(auto it:adj[node])
            {
                int nextNode=it.first;
                double wt=it.second;
                if((double)(rate*wt)>cost[nextNode])
                {
                    cost[nextNode]=rate*wt;
                    st.insert({cost[nextNode],nextNode});
                }
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,int>mp;
        vector<vector<pair<int,double>>>adj;
        int cnt=0;
        int n=values.size();
        for(int i=0;i<n;++i)
        {
            string u=equations[i][0],v=equations[i][1];
            if(!mp.count(u))
            {
                mp[u]=cnt++;
                adj.push_back({});
            }

            if(!mp.count(v))
            {
                mp[v]=cnt++;
                adj.push_back({});
            }

            int F=mp[u],S=mp[v];
            adj[F].push_back({S,values[i]});
            adj[S].push_back({F,1/values[i]});
        }

        vector<double>ans;

        for(auto it:queries)
        {
            string F=it[0],S=it[1];

            if(!mp.count(F) || !mp.count(S))
            {
                ans.push_back(-1.0);
                continue;
            }

            if(F==S)
            {
                ans.push_back(1.0);
                continue;
            }
            ans.push_back(price(mp[F],mp[S],adj));
        }
        return ans;
    }
};