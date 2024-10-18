class Solution {
public:
    void recur(vector<int>&nums,int ind,int curr,int mx,int &cnt)
    {
        if(curr==mx)
            ++cnt;
        for(int i=ind;i<nums.size();++i)
            recur(nums,i+1,curr|nums[i],mx,cnt);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int mx=0,cnt=0;
        for(int i:nums)
            mx|=i;
        recur(nums,0,0,mx,cnt);
        return cnt;
    }
};