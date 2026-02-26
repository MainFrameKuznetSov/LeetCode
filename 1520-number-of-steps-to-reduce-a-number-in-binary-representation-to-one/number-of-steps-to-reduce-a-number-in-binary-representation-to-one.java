class Solution {
    public int numSteps(String s) {
        int n=s.length();
        int ans=0,extra=0;
        for(int i=n-1;i>0;--i)
        {
            int dig=(s.charAt(i)-'0')+extra;
            if((dig&1)==1)
            {
                ans+=2;
                extra=1;
            }
            else
                ++ans;
        }
        return ans+extra;
    }
}