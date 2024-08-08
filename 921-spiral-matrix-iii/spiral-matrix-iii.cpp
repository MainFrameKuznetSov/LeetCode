class Solution {
public:
    bool isValid(int i, int j, int n, int m) 
    {
        return (i>=0 && j>=0 && i<n && j<m);
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int remaining=rows*cols;
        vector<vector<int>>ans;
        ans.push_back({rStart,cStart});
        --remaining;
        int currMoves=2;
        while(remaining>0)
        {
            for(int i=0;i<currMoves-1;++i) 
            {
                ++cStart;
                if(isValid(rStart,cStart,rows,cols)) 
                {
                    --remaining;
                    ans.push_back({rStart,cStart});
                }
            }
            for(int i=0;i<currMoves-1;++i) 
            {
                ++rStart;
                if(isValid(rStart,cStart,rows,cols)) 
                {
                    --remaining;
                    ans.push_back({rStart,cStart});
                }
            }
            for(int i=0;i<currMoves;++i) 
            {
                --cStart;
                if(isValid(rStart,cStart,rows,cols)) 
                {
                    --remaining;
                    ans.push_back({rStart,cStart});
                }
            }
            for(int i=0;i<currMoves;++i) 
            {
                --rStart;
                if(isValid(rStart,cStart,rows,cols)) 
                {
                    --remaining;
                    ans.push_back({rStart,cStart});
                }
            }
            currMoves+=2;
        }
        return ans;
    }
};