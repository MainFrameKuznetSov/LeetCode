class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<int>row,col;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(mat[i][j]==0)
                {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        for(int i=0;i<row.size();++i)
        {
            for(int j=0;j<m;++j)
                mat[row[i]][j]=0;
        }
        for(int i=0;i<col.size();++i)
        {
            for(int j=0;j<n;++j)
                mat[j][col[i]]=0;
        }
    }
};