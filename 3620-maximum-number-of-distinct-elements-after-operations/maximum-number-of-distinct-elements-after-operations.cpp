class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int prev=INT_MIN,ans=0;
        for(int i:nums)
        {
            int curr=max((i-k),prev+1);
            if(curr<=(i+k))
            {
                ++ans;
                prev=curr;
            }
        }
        return ans;
    }
};