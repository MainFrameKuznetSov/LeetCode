class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size(),ans=0;
        for(int i:nums)
            ans|=i;
        return ans*(1<<(n-1));
    }
};