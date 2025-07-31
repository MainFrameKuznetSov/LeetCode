class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        // vector<int>matrix[i-1](n,0);//O(n)
        // for(int i=0;i<n;++i)
        //     matrix[i-1][i]=matrix[0][i];
        for(int i=1;i<n;++i)//O(n^2)
        {
            // vector<int>matrix[i](n,INT_MAX);//O(n)
            for(int j=0;j<n;++j)
            {
                int up=matrix[i-1][j]+matrix[i][j];
                int ld=INT_MAX,rd=INT_MAX;
                if(j-1>=0)
                    ld=matrix[i-1][j-1]+matrix[i][j];
                if(j+1<n)
                    rd=matrix[i-1][j+1]+matrix[i][j];
                matrix[i][j]=min(up,min(ld,rd));
            }
            //matrix[i-1]=matrix[i];
        }
        int ans=INT_MAX;
        for(int i:matrix[n-1])
            ans=min(ans,i);
        return ans;
    }
};