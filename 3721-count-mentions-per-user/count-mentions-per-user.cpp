class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        sort(events.begin(),events.end(),[&](auto &x,auto &y)
            {
                if(x[1]!=y[1])
                    return stoi(y[1])>stoi(x[1]);
                return x[0]=="OFFLINE";
            }
        );

        vector<int>ans(n),lim(n,0);
        for(auto it:events)
        {
            int t=stoi(it[1]);
            if(it[0]=="MESSAGE")
            {
                if(it[2]=="ALL")
                {
                    for(int i=0;i<n;++i)
                        ++ans[i];
                }
                else if(it[2]=="HERE")
                {
                    for(int i=0;i<n;++i)
                    {
                        if(t>=lim[i])
                            ++ans[i];
                    }
                }
                else
                {
                    string temp;
                    stringstream ss(it[2]);
                    while(ss>>temp)
                    {
                        int ind=stoi(temp.substr(2));
                        ++ans[ind];
                    }
                }
            }
            else
            {
                int ind=stoi(it[2]);
                lim[ind]=t+60;
            }
        }
        return ans;

    }
};