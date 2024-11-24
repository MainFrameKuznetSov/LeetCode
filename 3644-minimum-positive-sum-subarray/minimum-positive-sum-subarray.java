class Solution {
    public int minimumSumSubarray(List<Integer> nums, int l, int r) {
        int ans=1<<30;
        for(int i=0;i<nums.size();++i)
        {
            int curr=0;
            for(int j=i;j<nums.size();++j)
            {
                curr+=nums.get(j);
                if((j-i+1)>=l && (j-i+1)<=r && curr>0)
                    ans=curr<ans?curr:ans;
            }
        }
        return ans==1<<30?-1:ans;
    }
}