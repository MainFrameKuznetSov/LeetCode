class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size(),ans=0;
        vector<int>pre(arr.begin(),arr.end()),suff(arr.begin(),arr.end());
        for(int i=1;i<n;++i)
            pre[i]=max(pre[i-1],pre[i]);
        for(int i=n-2;i>=0;--i)
            suff[i]=min(suff[i+1],suff[i]);
        for(int i=0;i<n;++i)
        {
            if(i==0 || suff[i]>pre[i-1])
                ++ans;
        }
        return ans;
    }
};