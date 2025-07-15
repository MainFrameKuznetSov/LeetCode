class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3)
            return 0;
        int vow=0,cons=0;
        string vowel="AEIOUaeiou";
        for(char c:word)
        {
            if(isalpha(c))
            {
                if(vowel.find(c)!=string::npos)
                    ++vow;
                else
                    ++cons;
            }
            else if(!isdigit(c))
                return 0;
        }
        return (vow && cons);
    }
};