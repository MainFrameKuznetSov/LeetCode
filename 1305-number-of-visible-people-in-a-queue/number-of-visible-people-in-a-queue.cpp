class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        vector<int>ans(n,0);
        stack<int>stk;
        for(int i=0;i<n;++i)
        {
            while(!stk.empty() && heights[stk.top()]<=heights[i])
            {
                ++ans[stk.top()];
                stk.pop();
            }
            if(!stk.empty())
                ++ans[stk.top()];
            stk.push(i);
        }
        return ans;
    }
};