class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size(),s1=0,s2=0,s3=0;
        int mx1=0,mx2=0,mx3=0;
        int idx1=0,idx2=0,idx3=k;
        vector<int>ans={0,k,2*k};

        for(int i=0;i<k;++i) 
        {
            s1+=nums[i];
            s2+=nums[i+k];
            s3+=nums[i+2*k];
        }
        mx1=s1;
        mx2=s1+s2;
        mx3=s1+s2+s3;

        for(int i=0;i<=n-3*k;++i) 
        {
            if(i) 
            {
                s1=s1-nums[i-1]+nums[i+k-1];
                s2=s2-nums[i+k-1]+nums[i+2*k-1];
                s3=s3-nums[i+2*k-1]+nums[i+3*k-1];
            }

            if(s1>mx1) 
            {
                mx1=s1;
                idx1=i;
            }

            if(mx1+s2>mx2) 
            {
                mx2=mx1+s2;
                idx2=idx1;
                idx3=i+k;
            }

            if(mx2+s3>mx3) 
            {
                mx3=mx2+s3;
                ans={idx2,idx3,i+2*k};
            }
        }
        return ans;
    }
};