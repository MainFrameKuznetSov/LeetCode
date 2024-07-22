class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string>ans;
        vector<pair<int,string>>pr;
        int n=heights.size();
        for(int i=0;i<n;++i)
            pr.push_back(make_pair(heights[i],names[i]));
        sort(pr.begin(),pr.end());
        for(int i=n-1;i>=0;--i)
            ans.push_back(pr[i].second);
        return ans;
    }
};