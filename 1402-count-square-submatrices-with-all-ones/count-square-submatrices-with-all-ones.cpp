class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        vector<int>prev(m,0);
        int ans=0;
        for(int i=0;i<m;++i)
        {
            prev[i]=matrix[0][i];
            ans+=prev[i];
        }
        for(int i=1;i<n;++i)
        {
            vector<int>curr(m,0);
            for(int j=0;j<m;++j)
                curr[j]=matrix[i][j];
            for(int j=1;j<m;++j)
            {
                if(matrix[i][j]==0)
                    continue;
                else
                    curr[j]=min(prev[j],min(curr[j-1],prev[j-1]))+1;
            }
            for(int j=0;j<m;++j)
                ans+=curr[j];
            prev=curr;
        }
        return ans;
    }
};