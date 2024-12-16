class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int>mp;
        for(auto it:rectangles)
        {
            ++mp[{it[0],it[1]}];
            ++mp[{it[2],it[3]}];
            --mp[{it[0],it[3]}];
            --mp[{it[2],it[1]}];
        }
        int chk=0;
        for(auto it:mp)
        {
            if(it.second)
            {
                if(abs(it.second)!=1)
                    return 0;
                ++chk;
            }
        }
        return (chk==4);
    }
};