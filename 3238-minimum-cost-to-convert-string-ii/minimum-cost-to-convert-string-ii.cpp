#define ll long long
#define INF (ll)1e18

class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int n=source.size(),cnt=0;
        unordered_map<string,int>idMap;
        for(auto it:original)
        {
            if(!idMap.count(it))
                idMap[it]=cnt++;
        }

        for(auto it:changed)
        {
            if(!idMap.count(it))
                idMap[it]=cnt++;
        }

        vector<vector<ll>>dist(cnt,vector<ll>(cnt,INF));
        for(int i=0;i<cnt;++i)
            dist[i][i]=0;

        for(int i=0;i<original.size();++i)
        {
            int u=idMap[original[i]],v=idMap[changed[i]];
            dist[u][v]=min(dist[u][v],(ll)cost[i]);
        }

        for(int i=0;i<cnt;++i)
        {
            for(int j=0;j<cnt;++j)
            {
                for(int k=0;k<cnt;++k)
                {
                    if(dist[j][i]!=INF && dist[i][k]!=INF)
                        dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
                }
            }
        }
        vector<ll>dp(n+1,INF);
        dp[0]=0LL;
        vector<int>temp;
        for(auto it:original)
            temp.push_back(it.size());
        sort(temp.begin(),temp.end());
        set<int>st(temp.begin(),temp.end());
        temp=vector<int>(st.begin(),st.end());
        st.clear();
        for(int i=0;i<n;++i)
        {
            if(dp[i]==INF)
                continue;
            if(source[i]==target[i])
                dp[i+1]=min(dp[i+1],dp[i]);
            for(int it:temp)
            {
                if(i+it>n)
                    break;
                string sub1=source.substr(i,it),sub2=target.substr(i,it);
                if(sub1==sub2)
                    dp[i+it]=min(dp[i+it],dp[i]);

                if(idMap.count(sub1) && idMap.count(sub2))
                {
                    int u=idMap[sub1],v=idMap[sub2];
                    if(dist[u][v]!=INF)
                        dp[i+it]=min(dp[i+it],dp[i]+dist[u][v]);
                }
                
            }
        }

        return dp[n]==INF?-1:dp[n];

    }
};