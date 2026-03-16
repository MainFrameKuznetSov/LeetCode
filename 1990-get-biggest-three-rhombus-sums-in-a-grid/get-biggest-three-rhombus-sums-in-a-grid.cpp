class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        set<int,greater<int>>st;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                st.insert(grid[i][j]);
                for(int k=1;k*2<n-i && j>=k && j<m-k;++k)
                {
                    int sum=0;
                    for(int l=0;l<k;++l)
                        sum+=grid[i+l][j+l];
                    for(int l=0;l<k;++l)
                        sum+=grid[i+k+l][j+k-l];
                    for(int l=0;l<k;++l)
                        sum+=grid[i+k*2-l][j-l];
                    for(int l=0;l<k;++l)
                        sum+=grid[i+k-l][j-k+l];
                    st.insert(sum);
                }
            }
        }
        vector<int>ans(st.begin(),st.end());
        if(ans.size()>3)
            ans.resize(3);
        return ans;
    }
};