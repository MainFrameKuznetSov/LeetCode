class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int id, int vd) {
        int n=nums.size();
        if(n==0 || id<0 || vd<0)
            return 0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;++i)
        {
            int temp=nums[i]/(vd+1);
            if(nums[i]<0)
                --temp;
            if(mp.find(temp)!=mp.end())
                return 1;
            else
            {
                mp[temp]=nums[i];
                if((mp.find(temp-1)!=mp.end() && nums[i]-mp[temp-1]<=vd) || (mp.find(temp+1)!=mp.end() && mp[temp+1]-nums[i]<=vd))
                    return 1;
                if(mp.size()>id)
                {
                    int chk=nums[i-id]/(vd+1);
                    if(nums[i-id]<0)
                        --chk;
                    mp.erase(chk);
                }
            }
        }
        return 0;
    }
};