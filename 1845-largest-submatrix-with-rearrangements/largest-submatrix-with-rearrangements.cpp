class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size(),ans=0;
        vector<int>hgt(m,0);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(matrix[i][j]==1)
                    ++hgt[j];
                else
                    hgt[j]=0;
            }
            vector<int>cpy=hgt;
            sort(cpy.begin(),cpy.end());
            reverse(cpy.begin(),cpy.end());
            for(int j=0;j<m;++j)
            {
                if(cpy[j]==0)
                    break;
                ans=max(ans,cpy[j]*(j+1));
            }
        }
        return ans;
    }
};