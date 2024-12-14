class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n=nums.size();
        long long cnt=0;
        map<int,int>mp;
        int l=0,r=0;
        while(r<n)
        {
            ++mp[nums[r]];
            while(l<r && (--mp.end())->first-mp.begin()->first>2)
            {
                int temp=--mp[nums[l]];
                if(temp==0)
                    mp.erase(nums[l]);
                ++l;
            }
            cnt+=(r-l+1);
            ++r;
        }
        return cnt;
    }
};