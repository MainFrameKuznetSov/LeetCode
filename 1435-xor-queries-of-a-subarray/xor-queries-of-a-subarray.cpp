class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int>pxor(n),ans(queries.size());
        pxor[0]=arr[0];
        for(int i=1;i<n;++i)
            pxor[i]=pxor[i-1]^arr[i];
        for(int i=0;i<queries.size();++i)
        {
            if(queries[i][0]==0)
                ans[i]=pxor[queries[i][1]];
            else
                ans[i]=pxor[queries[i][1]]^pxor[queries[i][0]-1];
        }
        return ans;
    }
};