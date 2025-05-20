class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size(),temp=0;
        vector<int>cnt(n+1,0);
        for(auto i:queries)
        {
            ++cnt[i[0]];
            --cnt[i[1]+1];
        }
        for(int i=0;i<n;++i)
        {
            temp+=cnt[i];
            if(temp<nums[i])
                return 0;
        }
        return 1;
    }
};