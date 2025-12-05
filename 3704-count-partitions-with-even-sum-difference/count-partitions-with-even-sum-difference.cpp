class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size(),sum=0;
        for(int i:nums)
            sum+=i;
        return sum&1?0:n-1;
    }
};