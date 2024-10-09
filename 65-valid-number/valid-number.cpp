class Solution {
private:
    bool solve(string &s, int ind) 
    {
        if(ind<s.size())
        {
            if(s[ind]=='-' || s[ind]=='+') 
                ++ind;
        }
        bool hasDigit=false;
        while(ind<s.size()) 
        {
            char ch=s[ind];
            if(!isdigit(ch)) 
                return false;
            hasDigit=true; 
            ++ind;
        }
        return hasDigit;
    }
    
public:
    bool isNumber(string s) 
    {
        bool dec=false;
        bool ans=false;  
        int i=0;
        if (s[i]=='-' || s[i]=='+') 
            ++i;
        while(i<s.size()) 
        {
            char ch=s[i];
            if(ch=='-' || ch=='+') 
                return false;
            else if(isalpha(ch)) 
            {
                if (ch=='e' || ch=='E') 
                {
                    if(ans && solve(s,i+1)) 
                        return true;
                    else 
                        return false;
                } 
                else 
                    return false;
            }
            else if(ch=='.') 
            {
                if(dec) 
                    return false;
                else 
                    dec=true;
            }
            else 
                ans=true; 
            ++i;
        }
        return ans;
    }
};