class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int>mp;
        // for(int i:nums)
        //     cout<<i<<" ";
        // cout<<"\n";
        for(int i:nums)
        {
            int rem=(i%value+value)%value;
            ++mp[rem];
        }
        int ans=0;
        while(mp[ans%value])
        {
            --mp[ans%value];
            ++ans;
        }
        return ans;
    }
};