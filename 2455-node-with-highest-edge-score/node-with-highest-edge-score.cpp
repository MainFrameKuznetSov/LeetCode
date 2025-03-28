class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n=edges.size();
        long long mx=0,ans=-1;
        vector<int>adj[n];
        for(int i=0;i<n;++i)
            adj[edges[i]].push_back(i);
        for(int i=0;i<n;++i)
        {
            long long sum=0;
            for(auto it:adj[i])
                sum+=it;
            //cout<<i<<" "<<sum<<" "<<mx<<"\n";
            if(sum>mx)
            {
                mx=sum;
                ans=i;
            }
        }
        return (int)ans;
    }
};