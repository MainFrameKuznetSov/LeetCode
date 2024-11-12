class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        vector<pair<int,int>>pr;
        int mx=0;
        for(auto iter:items) 
        {
            mx=max(mx,iter[1]);
            pr.push_back({iter[0],mx});
        }
        vector<int>ans;
        for(int iter:queries) 
        {
            auto it=upper_bound(pr.begin(),pr.end(),make_pair(iter,INT_MAX))-1;
            if(it>=pr.begin())
                ans.push_back(it->second);
            else
                ans.push_back(0);
        }
        return ans;
    }
};