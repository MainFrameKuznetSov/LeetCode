class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mat) {
        long long mn=INT_MAX,sum=0,ng=0;
        for(int i=0;i<mat.size();++i)
        {
            for(int j=0;j<mat[0].size();++j)
            {
                if(mat[i][j]<0)
                    ++ng;
                long long mod=abs(mat[i][j]);
                mn=min(mn,mod);
                sum+=mod;
            }
        }
        return (ng%2==0)?sum:sum-(mn*2);
    }
};