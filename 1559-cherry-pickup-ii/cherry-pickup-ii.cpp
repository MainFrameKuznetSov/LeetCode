class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>prev(n,vector<int>(n,0));
        for(int y1=0;y1<n;++y1)
        {
            for(int y2=0;y2<n;++y2)
                prev[y1][y2]=(y1==y2)?grid[m-1][y1]:grid[m-1][y1]+grid[m-1][y2];
        }
        for(int i=m-2;i>=0;--i)
        {
            vector<vector<int>>curr(n,vector<int>(n,0));
            for(int y1=0;y1<n;++y1)
            {
                for(int y2=0;y2<n;++y2)
                {
                    int maxi=INT_MIN;
                    for(int dy1=1;dy1>=-1;--dy1)
                    {
                        for(int dy2=1;dy2>=-1;--dy2)
                        {
                            int temp=(y1==y2)?grid[i][y1]:grid[i][y1]+grid[i][y2];
                            if(y1+dy1>=0 && y1+dy1<n && y2+dy2>=0 && y2+dy2<n)
                                temp+=prev[y1+dy1][y2+dy2];
                            else
                                temp=INT_MIN;
                            maxi=max(maxi,temp);
                        }
                    }
                    curr[y1][y2]=maxi;
                }
            }
            prev=curr;
        }
        return prev[0][n-1];
    }
};