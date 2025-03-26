class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n=grid.size(),m=grid[0].size();
        vector<int>v;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
                v.push_back(grid[i][j]);
        }
        sort(v.begin(),v.end());
        int mod=v[0]%x;
        for(int i=1;i<(n*m);++i)
        {
            if(mod!=v[i]%x)
                return -1;
        }
        int mid=(n*m)/2,ans=0;
        for(int i=0;i<(n*m);++i)
        {
            if(i==mid)
                continue;
            ans+=abs(v[i]-v[mid])/x;
        }
        return ans;
    }
};