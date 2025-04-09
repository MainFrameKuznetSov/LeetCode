class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        if(k>nums[0])
            return -1;
        unordered_set<int>st;
        for(int i:nums)
        {
            if(i>k)
                st.insert(i);
        }
        return (int)st.size();
    }
};