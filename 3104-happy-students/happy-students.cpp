class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=0,n=nums.size();
        if(nums[0]!=0)
            ++cnt;
        for(int i=0;i<n-1;++i)
        {
            if((i+1)>nums[i] && (i+1)<nums[i+1])
                cnt++;
        }
        ++cnt;
        return cnt;
    }
};