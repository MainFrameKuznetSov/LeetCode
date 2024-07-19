class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<int>ans;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                int mx=matrix[i][j],mn=matrix[i][j];
                for(int k=0;k<m;++k)
                    mn=min(mn,matrix[i][k]);
                for(int k=0;k<n;++k)
                    mx=max(mx,matrix[k][j]);
                if(mn==mx)
                    ans.push_back(mn);
            }
        }
        return ans;
    }
};