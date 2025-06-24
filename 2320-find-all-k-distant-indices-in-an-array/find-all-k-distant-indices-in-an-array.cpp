class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>ans;
        int n=nums.size(),i,j=0;
        for(i=0;i<n;++i)
        {
            //j=0;
            if(nums[i]==key)
            {
                for(j=max(j,i-k);j-k<=i && j<n;++j)
                    ans.push_back(j);
            }
        }
        return ans;
    }
};