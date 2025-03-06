class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size(),miss=0,repeat=0;
        unordered_map<int,int>mp;
        for(int i=1;i<=(n*n);++i)
        {
            miss^=i;
            ++mp[i];
        }
        //cout<<miss<<"\n";
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                // repeat.erase(grid[i][j]);
                if(mp[grid[i][j]]==1)
                {
                    mp.erase(grid[i][j]);
                    miss^=grid[i][j];
                }
                else 
                {
                    mp.erase(grid[i][j]);
                    repeat=grid[i][j];
                }
            }
        }
        return {repeat,miss};
    }
};