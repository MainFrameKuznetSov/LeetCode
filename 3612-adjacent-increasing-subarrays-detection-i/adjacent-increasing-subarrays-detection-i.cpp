class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if(k==1)
            return 1;
        int cnt=0,n=nums.size();
        set<int>st;
        for(int i=0;i<n;++i)
        {
            vector<int>temp;
            for(int j=0;j<k;++j)
            {
                if(i+j<n)
                    temp.push_back(nums[i+j]);
            }
            if(temp.size()<k)
                continue;
            bool f=1;
            for(int j=0;j<temp.size()-1;++j)
            {
                if(temp[j+1]<=temp[j])
                {
                    f=0;
                    break;
                }
            }
            if(f) 
                st.insert(i);
        }
        for(auto iter:st)
        {
            if(st.count(iter+k))
                return 1;
        }
        return 0;
    }
};