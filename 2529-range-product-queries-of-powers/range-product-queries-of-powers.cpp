#define MOD 1000000007

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>pwr,ans;
        int exp=0;
        while(n)
        {
            int rem=n%2;
            if(rem)
                pwr.push_back(1<<exp);
            n=n>>1;
            ++exp;
        }
        for(auto it:queries)
        {
            int left=it[0],right=it[1];
            long long prod=1;
            for(int i=left;i<=right;++i)
            {
                prod*=pwr[i];
                prod=prod%MOD;
            }
            ans.push_back((int)prod);
        }
        return ans;
    }
};