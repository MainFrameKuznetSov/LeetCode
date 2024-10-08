class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>prev(n,0);
        prev[0]=1;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                int up=0,left=0;
                if(i==0 && j==0)
                    continue;
                if(i>0)
                    up=prev[j];
                if(j>0)
                    left=prev[j-1];
                prev[j]=up+left;                    
            }
            //prev=curr;
        }
        return prev[n-1];
    }
};