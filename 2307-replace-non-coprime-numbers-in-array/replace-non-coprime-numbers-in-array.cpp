class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int it:nums)
        {
            while(!ans.empty())
            {
                int pre=ans.back(),curr=it,GCD=__gcd(pre,curr);
                if(GCD==1)
                    break;
                ans.pop_back();
                int LCM=(pre*1LL*curr)/GCD;
                it=LCM;
            }
            ans.push_back(it);
        }
        return ans;
    }
};