class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>pprod(n+1,1),sprod(n+1,1),ans(n,1);
        for(int i=0;i<n;++i)
            pprod[i+1]=pprod[i]*nums[i];
        for(int i=n-1;i>=0;--i)
            sprod[i]=sprod[i+1]*nums[i];
        // for(int i:pprod)
        //     cout<<i<<" ";
        // cout<<"\n";
        // for(int i:sprod)
        //     cout<<i<<" ";
        // cout<<"\n";
        for(int i=0;i<n;++i)
            ans[i]=pprod[i]*sprod[i+1];
        return ans;
    }
};