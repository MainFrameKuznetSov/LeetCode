class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>ans(n,vector<int>(n,0));
        for(int i=0;i<n;++i)
        {
            int row=i,col=0;
            vector<int>temp;
            while(row<n && col<n)
                temp.push_back(grid[row++][col++]);
            sort(temp.begin(),temp.end(),greater<int>());
            row=i,col=0;
            int ptr=0;
            while(row<n && col<n && ptr<temp.size())
                ans[row++][col++]=temp[ptr++];
        }
        for(int i=0;i<n-1;++i)
        {
            int row=0,col=i+1;
            vector<int>temp;
            while(row<n-1 && col<n)
                temp.push_back(grid[row++][col++]);
            sort(temp.begin(),temp.end());
            row=0,col=i+1;
            int ptr=0;
            while(row<n-1 && col<n && ptr<temp.size())
                ans[row++][col++]=temp[ptr++];
        }
        return ans;
    }
};