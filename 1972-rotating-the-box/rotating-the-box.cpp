class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size(),m=box[0].size();
        vector<vector<char>>res(m,vector<char>(n,'.'));
        
        for(int i=0;i<n;++i) 
        {
            int temp=m-1;
            for(int j=m-1;j>=0;--j) 
            {
                if(box[i][j]=='#') 
                {
                    res[temp][n-i-1]='#';
                    --temp;
                }
                else if(box[i][j]=='*') 
                {
                    res[j][n-i-1]='*';
                    temp=j-1;
                }
            }
        }
        return res;
    }
};