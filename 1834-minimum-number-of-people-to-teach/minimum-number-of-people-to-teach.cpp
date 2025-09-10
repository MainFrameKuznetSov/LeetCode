class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int>users;
        for(auto &friends:friendships) 
        {
            int u=friends[0]-1,v=friends[1]-1;
            unordered_set<int>langSet(begin(languages[u]),end(languages[u]));
            bool isTalkable=false;
            for(int lang:languages[v]) 
            {
                if(langSet.count(lang)) 
                {
                    isTalkable=true;
                    break;
                }
            }

            if(!isTalkable) 
            {
                users.insert(u);
                users.insert(v);
            }
        }

        vector<int>language(n+1,0);
        int mostCommon=0;

        for(int user:users) 
        {
            for(int lang:languages[user]) 
            {
                ++language[lang];
                mostCommon=max(mostCommon,language[lang]);
            }
        }

        return users.size()-mostCommon;
    }
};