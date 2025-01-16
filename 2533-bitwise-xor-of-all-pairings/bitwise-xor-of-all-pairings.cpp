class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        unordered_map<long long,long long>mp;
        for(long long i:nums1)
            mp[i]+=m;
        for(long long i:nums2)
            mp[i]+=n;
        int ans=0;
        for(auto it:mp)
        {
            if(it.second & 1)
                ans^=it.first;
        }
        return ans;
    }
};