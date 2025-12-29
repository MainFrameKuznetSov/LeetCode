class Solution {
public:

    unordered_map<string,vector<char>>mp;

    bool solve(string bottom,int ind,string str)
    {
        if(bottom.size()==1)
            return 1;
        if(ind+1==bottom.size())
        {
            string newS;
            return solve(str,0,newS);
        }
        string fst=bottom.substr(ind,2);
        for(char it:mp[fst])
        {
            str.push_back(it);
            if(solve(bottom,ind+1,str))
                return 1;
            str.pop_back();
        }
        return 0;

    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(auto it:allowed)
            mp[it.substr(0,2)].push_back(it[2]);
        string str;
        return solve(bottom,0,str);
    }
};