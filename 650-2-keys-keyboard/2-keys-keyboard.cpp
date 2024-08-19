class Solution {
public:
    int minSteps(int n) {
        int ans=0,step=2;
        while(n>1)
        {
            while(n%step==0)
            {
                ans+=step;
                n/=step;
            }
            ++step;
        }
        return ans;
    }
};