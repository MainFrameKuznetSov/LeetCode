class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minR=INT_MAX,maxR=INT_MIN,minC=INT_MAX,maxC=INT_MIN;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                if(grid[i][j]==1)
                {
                    minR=min(minR,i);
                    maxR=max(maxR,i);
                    minC=min(minC,j);
                    maxC=max(maxC,j);
                }
            }
        }
        if(minR==INT_MAX || maxR==INT_MIN || minC==INT_MAX || maxC==INT_MIN)
            return 0;
        int ans=(maxR-minR+1)*(maxC-minC+1);
        return ans;
    }
};