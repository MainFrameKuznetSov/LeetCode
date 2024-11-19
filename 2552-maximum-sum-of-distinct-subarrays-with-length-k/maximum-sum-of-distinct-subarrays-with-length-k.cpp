class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_set<int>st;
        long long curr=0;
        long long mx=0;
        int l=0;
        for(int r=0;r<n;++r) 
        {
            if(st.find(nums[r])==st.end()) 
            {
                curr+=nums[r];
                st.insert(nums[r]);
                if(r-l+1==k) 
                {
                    mx=max(mx,curr);
                    curr-=nums[l];
                    st.erase(nums[l]);
                    ++l;
                }
            } 
            else 
            {
                while(nums[l]!=nums[r]) 
                {
                    curr-=nums[l];
                    st.erase(nums[l]);
                    ++l;
                }
                ++l;
            }
        }
        return mx;
    }
};