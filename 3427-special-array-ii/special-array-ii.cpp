class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>pre(n,0);
        for(int i=1;i<n;++i)
        {
            pre[i]=pre[i-1];
            if(nums[i-1]%2==nums[i]%2)
                ++pre[i];
        }
        vector<bool>ans;
        for(auto it:queries)
        {
            int chk=pre[it[1]]-(pre[it[0]]>0?pre[it[0]]:0);
            ans.push_back(chk==0);
        }
        return ans;
    }
};