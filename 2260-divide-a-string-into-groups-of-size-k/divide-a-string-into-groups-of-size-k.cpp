class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        for(int i=0;i<s.size();i+=k)
        {
            string sub=s.substr(i,k);
            if(sub.size()==k)
            {
                ans.push_back(sub);
                continue;
            }
            int len=sub.size();
            for(int j=0;j<k-len;++j)
                sub+=fill;
            ans.push_back(sub);
        }
        return ans;
    }
};