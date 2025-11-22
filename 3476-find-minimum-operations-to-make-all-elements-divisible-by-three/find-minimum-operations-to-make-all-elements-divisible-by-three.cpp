class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();++i)
            ans+=nums[i]%3==0?0:1;
        return ans;
    }
};