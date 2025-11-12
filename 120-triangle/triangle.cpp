class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int>pre(n,0);
        pre[0]=triangle[0][0];
        for(int i=1;i<n;++i)
        {
            vector<int>cur(n,0);
            for(int j=0;j<=i;++j)
            {
                if(j==i)
                    cur[j]=INT_MAX;
                else
                    cur[j]=pre[j];
                if(j-1>=0)
                    cur[j]=min(cur[j],pre[j-1]);
                cur[j]+=triangle[i][j];
            }
            pre=cur;
            cur.clear();
        }
        int ans=INT_MAX;
        for(int i=0;i<n;++i)
        {
            //cout<<pre[i]<<" ";
            ans=min(ans,pre[i]);
        }
        return ans;
    }
};