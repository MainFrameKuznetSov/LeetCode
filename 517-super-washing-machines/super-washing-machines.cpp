class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n=machines.size(),ans=0;
        vector<int>pre(n+1,0);
        for(int i=0;i<n;++i)
            pre[i+1]=pre[i]+machines[i];
        if(pre[n]%n!=0)
            return -1;

        int avg=pre[n]/n;
        for(int i=0;i<n;++i)
        {
            int l=(i*avg)-pre[i],r=(n-i-1)*avg-(pre[n]-pre[i]-machines[i]);
            if(l>0 && r>0)
                ans=max(ans,abs(l)+abs(r));
            else
                ans=max(ans,max(abs(l),abs(r)));
        }
        return ans;
    }
};