class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int>prev(n,0);
        for(int i=0;i<n;++i)
            prev[i]=triangle[n-1][i];
        for(int i=n-2;i>=0;--i)
        {
            vector<int>curr(n,0);
            for(int j=i;j>=0;--j)
            {
                int d=triangle[i][j],rd=triangle[i][j];
                d+=prev[j];
                rd+=prev[j+1];
                curr[j]=min(d,rd);
            }
            prev=curr;
        }
        return prev[0];
    }
};