class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,set<int>>mp;
        map<int,int>mp2;
        vector<int>ans;
        for(auto it:queries)
        {
            if(mp2.find(it[0])!=mp2.end())
            {
                int prev=mp2[it[0]];
                mp[prev].erase(it[0]);
                if(mp[prev].empty())
                    mp.erase(prev);
            }
            mp2[it[0]]=it[1];
            mp[it[1]].insert(it[0]);
            ans.push_back(mp.size());
        }  
        return ans;
    }
};