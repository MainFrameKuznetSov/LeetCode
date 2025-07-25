class Solution {
public:

    void reverse(vector<int>&nums,int l,int r)
    {
        int n=nums.size();
        while(l<r && l<n && r>=0)
            swap(nums[l++],nums[r--]);
    }

    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
    }
};