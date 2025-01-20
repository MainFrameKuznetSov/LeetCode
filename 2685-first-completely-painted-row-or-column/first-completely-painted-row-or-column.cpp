class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int r=mat.size(),c=mat[0].size();
        unordered_map<int,pair<int,int>>mp;
        vector<int>row(r,c),col(c,r);
        for(int i=0;i<r;++i)
        {
            for(int j=0;j<c;++j)
                mp[mat[i][j]]={i,j};
        }
        for(int i=0;i<arr.size();++i)
        {
            int temp=arr[i];
            auto [F,S]=mp[temp];
            --row[F];
            --col[S];
            if(row[F]==0 || col[S]==0)
                return i;
        }
        return -1;
    }
};