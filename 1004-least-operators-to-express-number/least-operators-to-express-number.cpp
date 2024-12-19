class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        if(target<x)
            return min(target*2-1,(x-target)*2);
        if(x==target)
            return 0;
        long long sum=x;
        int time=0;
        while(sum<target)
        {
            ++time;
            sum*=x;
        }
        if(sum==target)
            return time;
        int l=INT_MAX,r=INT_MAX;
        if(sum<target*2)
            l=leastOpsExpressTarget(x,sum-target)+time;
        r=leastOpsExpressTarget(x,target-(sum/x))+time-1;
        return min(l,r)+1;
    }
};