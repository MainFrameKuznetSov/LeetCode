class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        vector<vector<int>>ans=grid;
        int top=x,bottom=x+k-1;
        while(top<bottom)
        {

            for(int i=0;i<k && y+i<grid[0].size();++i)
                swap(ans[top][y+i],ans[bottom][y+i]);
            ++top;
            --bottom;
        }
        return ans;
    }
};