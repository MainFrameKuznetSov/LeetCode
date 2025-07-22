class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st;
        int l=0,sum=0,ans=0;
        for(int r=0;r<n;++r)
        {
            while(st.count(nums[r]))
            {
                sum-=nums[l];
                st.erase(nums[l]);
                ++l;
            }
            sum+=nums[r];
            st.insert(nums[r]);
            ans=max(ans,sum);
        }
        return ans;
    }
};