class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        long double maxi=INT_MIN,prod=1;
        for(int i=0;i<n;++i)
        {
            prod*=nums[i];
            maxi=max(prod,maxi);
            if(prod==0)
                prod=1;
        }
        prod=1;
        for(int i=n-1;i>=0;--i)
        {
            prod*=nums[i];
            maxi=max(prod,maxi);
            if(prod==0)
                prod=1;
        }
        return (int)maxi;
    }
};