class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        set<pair<int,int>>st,stk;
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;++i)
        {
            st.insert({nums[i],i}); 
            if(st.size()>k)
                st.erase(st.begin());
        }
        while(!st.empty())
        {
            auto top=*st.begin();
            st.erase(top);
            stk.insert({top.second,top.first});
        }
        while(!stk.empty())
        {
            auto top=*stk.begin();
            stk.erase(top);
            ans.push_back(top.second);
        }
        return ans;
    }
};