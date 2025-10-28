class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size(),ans=0,sum=0;
        for(int i:nums)
            sum+=i;
        int L=0,R=sum;
        for(int i:nums)
        {
            if(i==0)
            {
                if(L>=R && L<=R+1)
                    ++ans;
                if(R>=L && R<=L+1)
                    ++ans;
            }
            else
            {
                L+=i;
                R-=i;
            }
        }
        return ans;
    }
};