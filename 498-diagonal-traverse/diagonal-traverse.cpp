class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        map<int,vector<int>>mp;
        vector<int>ans;
        for(int i=0;i<n;++i)//fill using i+j
        {
            for(int j=0;j<m;++j)
                mp[i+j].push_back(mat[i][j]);
        }
        bool flip=1;
        for(auto &it:mp)
        {
            if(flip)
                reverse(it.second.begin(),it.second.end());
            for(int i:it.second)
                ans.push_back(i);
            flip=1-flip;
        }
        return ans;
    }
};