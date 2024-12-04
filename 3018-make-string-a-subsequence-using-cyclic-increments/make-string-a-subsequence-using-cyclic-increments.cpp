class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int chk=0,ans=str2.size();
        for(char c:str1)
        {
            if(chk<ans && (str2[chk]-c+26)%26<=1)
                ++chk;
        }
        return chk==ans;
    }
};