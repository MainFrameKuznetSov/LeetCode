class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n=edges.size(),ans=0;
        vector<long long>sum(n,0);
        for(int i=0;i<n;++i)
            sum[edges[i]]+=i;
        for(int i=1;i<n;++i)
        {
            if(sum[i]>sum[ans])
                ans=i;
        }
        return ans;
    }
};