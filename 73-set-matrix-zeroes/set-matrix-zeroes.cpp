class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<pair<int,int>>cell;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(mat[i][j]==0)
                    cell.push_back({i,j});
            }
        }
        for(int i=0;i<cell.size();++i)
        {
            for(int j=0;j<m;++j)
                mat[cell[i].first][j]=0;
            for(int j=0;j<n;++j)
                mat[j][cell[i].second]=0;
        }
    }
};