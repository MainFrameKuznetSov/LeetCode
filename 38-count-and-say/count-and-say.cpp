class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string temp=countAndSay(n-1),ans="";
        int cnt=1;
        char prev=temp[0],ch;
        for(int i=1;i<temp.size();++i)
        {
            if(prev==temp[i])
                ++cnt;
            else
            {
                ans.push_back('0'+cnt);
                ans.push_back(prev);
                cnt=1;
                prev=temp[i];
            }
        }
        ans.push_back('0'+cnt);
        ans.push_back(prev);
        return ans;
    }
};