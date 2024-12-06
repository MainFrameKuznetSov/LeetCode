class Solution {
public:
    int maxPoints(vector<vector<int>>& pts) {
        int n=pts.size();
        if(n<=2)
            return n;
        int ans=2;
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                int mx=2;
                for(int k=0;k<n;++k)
                {
                    int x1=pts[i][0],y1=pts[i][1];
                    int x2=pts[j][0],y2=pts[j][1];
                    int x3=pts[k][0],y3=pts[k][1];
                    if((y2-y1)*(x3-x1)==(y3-y1)*(x2-x1) && (i!=k) && (j!=k))
                        ++mx;
                }
                ans=max(ans,mx);
            }
        }
        return ans;
    }
};