class Solution {
private:
    int solve(vector<int>&list,int target) 
    {
        int low=0,high=list.size();
        while(low<high) 
        {
            int mid=(low+high)/2;
            if(list[mid]<target)
                low=mid+1;
            else
                high=mid;
        }
        return low;
    }
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        unordered_map<int,int>mp;
        for(int i=0;i<nums1.size();++i)
            mp[nums1[i]]=i;
        vector<int>v;
        long long ans=0;
        for(int i:nums2) 
        {
            int ind=mp[i],lc=solve(v,ind),rc=(n-1-ind)-(v.size()-lc);
            ans+=(long long)lc*rc;
            int pos=solve(v,ind);
            v.insert(v.begin()+pos,ind);
        }
        return ans;
    }
};