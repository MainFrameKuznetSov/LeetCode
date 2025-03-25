class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || s.size()<=1) 
            return s; 
        
        vector<string>line(min(numRows,(int)s.size())); 
        int curr=0;
        bool f=0; 
        for(char c:s) 
        {
            line[curr]+=c;
            if(curr==0 || curr==numRows-1) 
                f=!f;
            curr+=f?1:-1;
        }
        string ans="";
        for(string i:line)
            ans+=i;        
        return ans;
    }
};