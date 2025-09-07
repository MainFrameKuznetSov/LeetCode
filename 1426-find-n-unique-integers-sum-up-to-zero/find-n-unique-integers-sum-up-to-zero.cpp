class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        if(n&1)
        {
            ans.push_back(0);
            int lim=1;
            for(int i=1;i<=n-1;i+=2)
            {
                ans.push_back(lim);
                ans.push_back(-lim);
                ++lim;
            }
        }
        else
        {
            int lim=1;
            for(int i=1;i<=n-1;i+=2)
            {
                ans.push_back(lim);
                ans.push_back(-lim);
                ++lim;
            }
        }
        return ans;
    }
};