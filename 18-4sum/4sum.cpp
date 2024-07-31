class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>res;
        set<vector<int>>temp;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                int k=j+1,m=n-1;
                while(k<m)
                {
                    long long sum=nums[i]*1LL+nums[j]*1LL+nums[k]*1LL+nums[m]*1LL;
                    if(sum<target)
                        ++k;
                    else if(sum==target)
                    {
                        temp.insert({nums[i],nums[j],nums[k],nums[m]});
                        ++k;
                        --m;
                    }
                    else
                        --m;
                }
            }
        }
      for(auto iter:temp)
          res.push_back(iter);
      return res;
    }
};