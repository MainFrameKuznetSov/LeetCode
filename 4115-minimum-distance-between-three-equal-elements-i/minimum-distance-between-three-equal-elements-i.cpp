class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>temp(n+1);
        for(int i=0;i<n;++i)
            temp[nums[i]].push_back(i);
        int ans=(int)2e9;
        for(int i=1;i<=n;++i)
        {
            auto &it=temp[i];
            if(it.size()<3)
                continue;
            for(int j=0;j+2<it.size();++j)
                ans=min(ans,(it[j+2]-it[j])*2);            
        }
        return (ans==(int)2e9)?-1:ans;
    }
};