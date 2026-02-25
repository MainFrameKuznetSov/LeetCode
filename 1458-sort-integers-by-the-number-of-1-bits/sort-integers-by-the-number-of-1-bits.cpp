class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>pr;
        for(int i:arr)
            pr.push_back({i,__builtin_popcount(i)});
        sort(pr.begin(),pr.end(),[&](auto a,auto b)
        {
            if(a.second!=b.second)
                return a.second<b.second;
            return a.first<b.first;
        });
        vector<int>ans;
        for(auto i:pr)
            ans.push_back(i.first);
        return ans;
    }
};