class Solution {
public:
    vector<string> removeInvalidParentheses(string &s) {
        int count=0,n=s.size(); 
        for(auto it:s) 
        {
            if(it=='(' || it==')') 
                ++count; 
        }
        vector<string> store; 
        store.push_back(""); 
        int minRemovals=n; 
        for(int mask=0;mask<(1<<count);++mask)
        {
            int bit=0,counter=0; 
            string curr; 
            int currRemovals=0; 
            for(int i=0;i<n;++i) 
            {
                if(s[i]=='(') 
                {
                    if(mask & (1<<bit)) 
                    {
                        counter++; 
                        curr+=s[i]; 
                    } 
                    else
                        currRemovals++; 
                    bit++; 
                } 
                else if(s[i]==')') 
                {
                    if(mask & (1<<bit)) 
                    {
                        if(!counter) 
                        {
                            currRemovals=n; 
                            break; 
                        } 
                        else 
                        {
                            counter--; 
                            curr+=s[i]; 
                        }
                    } 
                    else 
                        currRemovals++; 
                    bit++; 
                } 
                else
                    curr+=s[i]; 
            }
            if(!counter) 
            {
                if(currRemovals<minRemovals) 
                {
                    store.clear(); 
                    minRemovals=currRemovals; 
                    store.push_back(curr); 
                } 
                else if(currRemovals==minRemovals)
                    store.push_back(curr); 
            }
        }
        vector<string>ans; 
        map<string,int>mp; 
        for(auto it:store) 
        {
            if(!mp[it]) 
            {
                ans.push_back(it); 
                mp[it]=1; 
            }
        }
        return ans; 
    }
};