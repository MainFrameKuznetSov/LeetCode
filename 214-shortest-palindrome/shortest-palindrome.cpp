class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.size(),prev=0,curr=n-1;
        while(curr>=0)
        {
            while(curr>=0 && s[prev]==s[curr])
            {
                ++prev;
                --curr;
            }
            --curr;
        }
        if(prev==n)
            return s;
        string half=s.substr(prev),rem=half;
        reverse(rem.begin(),rem.end());
        return rem+shortestPalindrome(s.substr(0,prev))+half;
    }
};