class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size(),ans=0;
        vector<long long>pre(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;++i)
            pre[i]=pre[i-1]+nums[i];
        /*
        for(int i=0;i<n;++i)
            cout<<pre[i]<<" ";
        cout<<"\n\n";
        */
        for(int i=0;i<n-1;++i)
        {
            //cout<<i<<"\n";
            //cout<<pre[i]<<" "<<(pre[n-1]-pre[i])<<"\n";
            if(pre[i]>=(pre[n-1]-pre[i]))
                ++ans;
        }
        return ans;
    }
};