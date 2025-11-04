class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size(),ind=0;
        vector<int>ans(n-k+1);
        for(int i=0;i<=n-k;++i)
        {
            unordered_map<int,int>mp;
            for(int j=i;j<i+k;++j)
                ++mp[nums[j]];
            vector<pair<int,int>>pr;
            for(auto it:mp)
                pr.push_back({it.second,it.first});
            sort(pr.begin(),pr.end(),greater<pair<int,int>>());
            int temp=0;
            for(int j=0;j<x && j<pr.size();++j) 
                temp+=pr[j].first*pr[j].second;
            ans[ind++]=temp;
        }
        return ans;
    }
};