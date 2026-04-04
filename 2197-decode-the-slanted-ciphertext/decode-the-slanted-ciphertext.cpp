class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n=encodedText.size();
        if(rows==1)
            return encodedText;
        int lines=n/rows;
        string ans;
        ans.reserve(n);
        for(int i=0;i<lines;++i) 
        {
            int left=0,right=i;
            while(left<rows && right<lines) 
            {
                ans+=encodedText[left*lines+right];
                ++left;
                ++right;
            }
        }
        while(!ans.empty() && ans.back()==' ')
            ans.pop_back();
        return ans;
    }
};