class Solution {
    public int[] plusOne(int[] digits) {
        int n=digits.length;
        if(digits[n-1]<9)
        {
            digits[n-1]+=1;
            return digits;
        }
        int ans[]=new int[n+1];
        ans[0]=0;
        for(int i=0;i<n;++i)
            ans[i+1]=digits[i];
        for(int i=ans.length-1;i>0;--i)
        {
            if(ans[i]!=9)
            {
                ans[i]+=1;
                digits[i-1]+=1;
                return digits;
            }
            else
            {
                ans[i]=0;
                digits[i-1]=0;
            }

        }
        ans[0]+=1;
        return ans;
    }
}