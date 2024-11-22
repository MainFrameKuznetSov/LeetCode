class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int>mp;
        
        for(auto it:matrix) 
        {
            string str;
            if(it[0]==0) 
            {
                for(int val:it) 
                    str+=to_string(val);
            } 
            else 
            {
                for(int val:it) 
                    str+=to_string(val^1);
            }
            ++mp[str];
        }
        
        int ans=0;
        for(auto it:mp)
            ans=max(ans,it.second);
        return ans;
    }
};