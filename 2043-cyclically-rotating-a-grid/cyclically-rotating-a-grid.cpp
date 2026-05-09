class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int up=0,left=0,down=grid.size()-1,right=grid[0].size()-1;
        while(up<down && left<right)
        {
            int len=down-up,wdt=right-left,peri=(len+wdt)*2,rem=k%peri;
            while(rem--)
            {
                int val=grid[up][left];
                for(int i=left;i<right;++i)
                    grid[up][i]=grid[up][i+1];
                for(int i=up;i<down;++i)
                    grid[i][right]=grid[i+1][right];
                for(int i=right;i>left;--i)
                    grid[down][i]=grid[down][i-1];
                for(int i=down;i>up;--i)
                    grid[i][left]=grid[i-1][left];
                grid[up+1][left]=val;
            }
            ++up;
            ++left;
            --down;
            --right;
        }
        return grid;
    }
};