class Solution {
public:
    string makeLargestSpecial(string s) {
        int ind=0,c0=0,c1=0,n=s.size();
        vector<string>ans;
        for(int i=0;i<n;++i) 
        {
            if (s[i]=='1')
                ++c1;
            else
                ++c0;
            if(c0==c1) 
            {
                ans.push_back('1'+makeLargestSpecial(s.substr(ind+1,i-ind-1))+'0');
                ind=i+1;
            }
        }
        sort(ans.rbegin(),ans.rend());
        string result;
        for (auto it:ans)
            result+=it;
        return result;
    }
};