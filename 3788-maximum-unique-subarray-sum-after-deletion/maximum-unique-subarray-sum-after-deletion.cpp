class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int>st;
        int sum=0,ans=INT_MIN,flag=1;
        for(int i:nums)
        {
            if(i>=0)
            {
                flag=0;
                if(!st.count(i))
                {
                    st.insert(i);
                    sum+=i;
                }
            }
            ans=max(ans,i);
        }
        return flag?ans:sum;
    }
};