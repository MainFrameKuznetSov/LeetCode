class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size(),ptr=0,ans=0;
        unordered_map<int,int>mp;
        int len=unordered_set<int>(nums.begin(),nums.end()).size();
        for(int i=0;i<n;++i)
        {
            ++mp[nums[i]];
            while(mp.size()==len)
            {
                ans+=n-i;
                --mp[nums[ptr]];
                if(mp[nums[ptr]]==0)
                    mp.erase(nums[ptr]);
                ++ptr;
            }
        }
        return ans;
    }
};