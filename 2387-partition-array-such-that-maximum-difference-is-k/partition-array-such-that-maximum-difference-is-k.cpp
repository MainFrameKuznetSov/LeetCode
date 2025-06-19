class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=1,mn=INT_MAX,mx=INT_MIN;
        for(int i:nums)
        {
            mn=min(mn,i);
            mx=max(mx,i);
            if(mx-mn>k)
            {
                ++ans;
                mx=i;
                mn=i;
            }
        }
        return ans;
    }
};