class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int>eleFreq,frqFreq;
        for(int i:nums)
            ++eleFreq[i];
        for(auto it:eleFreq)
            ++frqFreq[it.second];
        for(int i=0;i<nums.size();++i)
        {
            if(frqFreq[eleFreq[nums[i]]]==1)
                return nums[i];
        }
        return -1;
    }
};