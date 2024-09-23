class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end(),[](vector<int> &a,vector<int> &b) 
        {
            if(a[0]!=b[0]) 
                return a[0]<b[0]; 
            return a[1] > b[1]; 
        }
        );
        vector<int>hgt;
        for(auto iter:envelopes)
            hgt.push_back(iter[1]);
        vector<int>temp;
        for(auto iter:hgt)
        {
            if(temp.empty() || temp.back()<iter)
                temp.push_back(iter);
            else 
            {
                auto it=lower_bound(temp.begin(),temp.end(),iter);
                *it=iter;
            }
        }

        return temp.size();
    }
};