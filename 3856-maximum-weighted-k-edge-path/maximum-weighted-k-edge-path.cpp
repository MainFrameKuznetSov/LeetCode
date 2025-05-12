#define rep(i,n) for(int i=0;i<n;++i)
#define lloop(i,a,b) for(int i=(a);i<=(b);++i)
class Solution {
public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        vector<bitset<601>>prev(n);
        rep(i,n)
            prev[i].set(0);
        lloop(i,1,k)
        {
            vector<bitset<601>>curr(n);
            for(auto it:edges)
            {
                int u=it[0],v=it[1],wt=it[2];
                curr[v]=curr[v]|(prev[u]<<wt);
            }
            prev=curr;
        }
        int ans=-1;
        for(int i=t-1;i>=0;--i)
        {
            rep(j,n)
            {
                if(prev[j].test(i))
                    return i;
            }
        }
        return -1;
    }
};