class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,set<int>>mp;
        map<int,int>mp2;
        vector<int>ans;
        for (auto iter:queries)
        {
            if(mp2.find(iter[0])!=mp2.end())
            {
                int prev=mp2[iter[0]];
                mp[prev].erase(iter[0]);
                if(mp[prev].empty())
                    mp.erase(prev);
            }
            mp[iter[1]].insert(iter[0]);
            mp2[iter[0]]=iter[1];
            ans.push_back(mp.size());
        }  
        return ans;
    }
};