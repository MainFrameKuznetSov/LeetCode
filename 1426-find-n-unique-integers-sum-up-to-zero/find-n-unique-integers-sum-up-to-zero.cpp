class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        int lim=0;
        if(n&1)
        {
            ans.push_back(0);
            for(int i=1;i<=n-1;i+=2)
            {
                ans.push_back(++lim);
                ans.push_back(-lim);
            }
        }
        else
        {
            for(int i=1;i<=n-1;i+=2)
            {
                ans.push_back(++lim);
                ans.push_back(-lim);
            }
        }
        return ans;
    }
};