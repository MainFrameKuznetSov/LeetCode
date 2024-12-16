class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int mul) {
        for(int i=0;i<k;++i)
        {
            int mini=0;
            for(int j=0;j<nums.size();++j)
            {
                if(nums[j]<nums[mini])
                    mini=j;
            }
            nums[mini]*=mul;
        }
        return nums;
    }
};