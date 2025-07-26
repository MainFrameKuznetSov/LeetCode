class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int l=0,mid=0,r=n-1;
        for(int i=0;i<n;++i)
        {
            if(nums[mid]==0)
            {
                swap(nums[mid],nums[l]);
                ++mid;
                ++l;
            }
            else if(nums[mid]==1)
                ++mid;
            else
            {
                swap(nums[mid],nums[r]);
                --r;
            }
        }
    }
};