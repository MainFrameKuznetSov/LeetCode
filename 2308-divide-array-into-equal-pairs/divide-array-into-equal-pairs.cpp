class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i:nums)
            ++mp[i];
        for(auto it:mp)
        {
            if(it.second&1)
                return 0;
        }
        return 1;
    }
};