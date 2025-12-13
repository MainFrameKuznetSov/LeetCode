class Solution {
public:

    int priority(string s)
    {
        if(s=="electronics")
            return 0;
        if(s=="grocery")
            return 1;
        if(s=="pharmacy")
            return 2;
        if(s=="restaurant")
            return 3;
        return -1;
    }
    
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n=code.size();
        vector<pair<int,string>>v;
        for(int i=0;i<n;++i)
        {
            if(isActive[i])
            {
                int prior=priority(businessLine[i]);
                if(prior==-1)
                    continue;
                string s=code[i];
                if(s.empty())
                    continue;
                bool f=1;
                for(auto i:s)
                {
                    if(i!='_' && !isalnum(i))
                    {
                        f=0;
                        break;
                    }
                }
                if(!f)
                    continue;
                v.push_back({prior,s});
            }
        }

        sort(v.begin(),v.end());

        vector<string>ans;
        for(auto it:v)
            ans.push_back(it.second);

        return ans;
        
    }
};