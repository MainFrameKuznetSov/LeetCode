class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int,int>mp;
        int ans=0;
        for(auto it:dominoes)
        {
            ans+=mp[min(it[0],it[1])*10+max(it[0],it[1])];
            ++mp[min(it[0],it[1])*10+max(it[0],it[1])];
        }
        return ans;
    }
};