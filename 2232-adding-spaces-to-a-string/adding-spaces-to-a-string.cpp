class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        if(spaces.size()==0)
            return s;
        int ind=0;
        string ans="";
        for(int i=0;i<s.size();++i)
        {
            if(i==spaces[ind])
            {
                ans+=" ";
                ans+=s[i];
                if(ind!=spaces.size()-1)
                    ++ind;
            }
            else
                ans+=s[i];
            //cout<<ans<<"\n";
        }
        return ans;
    }
};