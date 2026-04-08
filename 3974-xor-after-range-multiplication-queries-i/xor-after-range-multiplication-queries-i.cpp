#define MOD (int)(1e9+7)

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto it:queries)
        {
            int l=it[0],r=it[1],f=it[2],s=it[3];
            for(int i=l;i<=r;i+=f)
                nums[i]=(1LL*nums[i]*s)%MOD;
        }
        int ans=0;
        for(int i:nums)
            ans^=i;
        return ans;
    }
};