class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>temp;
        for(int iter:nums)
            temp.push_back(to_string(iter));
        sort(temp.begin(),temp.end(),[&](string s,string t)
        {
            return s+t>t+s;
        }
        );
        if(temp[0]=="0")
            return "0";
        string ans="";
        for(string s:temp)
            ans+=s;
        return ans;
    }
};