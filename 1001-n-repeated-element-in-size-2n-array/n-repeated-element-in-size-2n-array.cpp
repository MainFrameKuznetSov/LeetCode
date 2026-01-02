class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int>st;
        for(int i:nums)
        {
            if(st.count(i))
                return i;
            st.insert(i);
        }
        return -1;
    }
};