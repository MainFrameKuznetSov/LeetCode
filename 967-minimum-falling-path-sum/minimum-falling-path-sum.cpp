class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int>prev(n,0);
        for(int i=0;i<n;++i)
            prev[i]=matrix[0][i];
        for(int i=1;i<n;++i)
        {
            vector<int>curr(n,0);
            for(int j=0;j<n;++j)
            {
                int up=matrix[i][j],rd=matrix[i][j],ld=matrix[i][j];
                up+=prev[j];
                if(j>0)
                    ld+=prev[j-1];
                else
                    ld=INT_MAX;
                if(j<n-1)
                    rd+=prev[j+1];
                else
                    rd=INT_MAX;
                curr[j]=min(up,min(ld,rd));
            }
            prev=curr;
        }
        int ans=INT_MAX;
        for(int i=0;i<n;++i)
            ans=min(ans,prev[i]);
        return ans;
    }
};