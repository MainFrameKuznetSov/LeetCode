class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<string>>mp;
        unordered_map<string,int>indeg;
        unordered_set<string>st(supplies.begin(),supplies.end());
        vector<string>ans;
        for(int i=0;i<recipes.size();++i)
        {
            string s=recipes[i];
            indeg[s]=ingredients[i].size();
            for(auto it:ingredients[i])
                mp[it].push_back(s);
        }

        queue<string>q(supplies.begin(),supplies.end());
        while(!q.empty())
        {
            string tp=q.front();
            q.pop();
            if(!mp.count(tp))
                continue;
            for(auto i:mp[tp])
            {
                --indeg[i];
                if(indeg[i]==0)
                {
                    ans.push_back(i);
                    q.push(i);
                }
            }
        }
        return ans;
    }
};