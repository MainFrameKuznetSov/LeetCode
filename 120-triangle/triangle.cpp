class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int>prev(1,triangle[0][0]);
        for(int i=1;i<n;++i)
        {
            vector<int>curr(i+1,INT_MAX);
            for(int j=0;j<i+1;++j)
            {
                if(j!=i)
                    curr[j]=triangle[i][j]+prev[j];
                if(j!=0)
                    curr[j]=min(curr[j],triangle[i][j]+prev[j-1]);
            }
            prev=vector<int>(i+1);
            prev=curr;
        }
        int ans=INT_MAX;
        for(int i:prev)
            ans=min(ans,i);
        return ans;
    }
};