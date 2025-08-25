class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size(),i=0,j=0;
        vector<int>ans;
        bool up=1;
        while(ans.size()<n*m)
        {
            ans.push_back(mat[i][j]);
            if(up)
            {
                if(j==m-1)//Top-right hit
                {
                    up=false;
                    ++i;
                }
                else if(i==0)//Boundary
                {
                    up=false;
                    ++j;
                }
                else//Normal
                {
                    --i;
                    ++j;
                }
            }
            else
            {
                if(i==n-1)//Bottom left
                {
                    up=true;
                    ++j;
                }
                else if(j==0)//Boundary
                {
                    up=true;
                    ++i;
                }
                else//Normal
                {
                    ++i;
                    --j;
                }
            }
        }
        return ans;
    }
};