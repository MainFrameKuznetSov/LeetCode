class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>>adj;
        unordered_map<int,int>deg;
        
        for(auto it:pairs) 
        {
            adj[it[0]].push_back(it[1]);
            ++deg[it[0]];
            --deg[it[1]];
        }
        
        int start=pairs[0][0];
        for(auto it:deg) 
        {
            if(it.second==1) 
            {
                start=it.first;
                break;
            }
        }
        
        vector<int>path;
        stack<int>stk;
        stk.push(start);
        
        while(!stk.empty()) 
        {
            auto& next=adj[stk.top()];
            if(next.empty()) 
            {
                path.push_back(stk.top());
                stk.pop();
            } 
            else 
            {
                int nextNode=next.back();
                stk.push(nextNode);
                next.pop_back();
            }
        }
        
        vector<vector<int>>ans;
        //ans.reserve((int)path.size()-1);
        
        for(int i=path.size()-1;i>0;--i) 
            ans.push_back({path[i],path[i-1]});
        
        return ans;
    }
};