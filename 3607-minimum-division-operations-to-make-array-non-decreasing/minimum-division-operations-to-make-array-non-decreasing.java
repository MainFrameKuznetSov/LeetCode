class Solution {
    public int getFact(int x) 
    {
        int ans=1;
        if (x<=2) 
            return ans;
        for(int i=2;i*i<=x;++i) 
        {
            if(x%i==0) 
                return (x/i);
        }
        return ans;
    }
    public int minOperations(int[] nums) {
        int ans=0;
        boolean flag=true;
        for(int i=1;i<nums.length;++i) 
        {
            if(nums[i]<nums[i-1]) 
            {
                flag=false;
                break;
            }
        }
        if(flag) 
            return 0;
        for(int i=0;i<nums.length-1;++i) 
        {
            int temp=getFact(nums[i]);
            nums[i]/=temp;
            if(temp!=1) 
                ++ans;
        }
        for(int i=1;i<nums.length;++i) 
        {
            if(nums[i-1]>nums[i]) 
                return -1;
        }
        return ans;
    }
}