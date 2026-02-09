class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
       int m=mat.size(),n=mat[0].size();
       vector<vector<int>>rowSum(m,vector<int>(n,0));
       for(int i=0;i<m;++i)
       {
           rowSum[i][0]=mat[i][0];
           for(int j=1;j<n;++j)
            rowSum[i][j]=rowSum[i][j-1]+mat[i][j];
       }
       int ans=0,l=0,r=min(n,m);
       while(l<=r)
       {
            int side=l+(r-l)/2;
            bool canDo=false;
            for(int i=0;i+side<=m;++i)
            {
                for(int j=0;j+side<=n;++j)
                {
                    int sum=0;
                    for(int k=i;k<i+side;k++)
                        sum+=rowSum[k][j+side-1]-(j==0?0:rowSum[k][j-1]);
                    if(sum<=threshold)
                    { 
                        canDo=true;
                        break;
                    }
                }
                if(canDo) 
                    break;
            }
            if(canDo)
            {
                ans=side;
                l=side+1;
            }
            else 
                r=side-1;
       } 
       return ans;
    }
};