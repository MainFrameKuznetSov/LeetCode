class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int>cpy(arr.begin(),arr.end());
        int rank=0;
        unordered_map<int,int>mp;
        for(auto iter:cpy)
            mp[iter]=++rank;
        vector<int>ans;
        for(int iter:arr)
            ans.push_back(mp[iter]);
        return ans;
    }
};