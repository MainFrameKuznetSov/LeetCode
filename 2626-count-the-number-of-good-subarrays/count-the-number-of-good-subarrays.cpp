class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans=0;
        unordered_map<int,int>mp;
        int left=0,right=0,n=nums.size();
        while(right<n)
        {
            k-=mp[nums[right]]++;
            while(k<=0)
                k+=--mp[nums[left++]];
            ans+=left;
            ++right;
        }
        return ans;
    }
};