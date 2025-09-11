class Solution {
public:
    string sortVowels(string s) {
        vector<char>vowel;
        for(char c:s)
        {
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
               c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
            vowel.push_back(c);
        }
        sort(vowel.begin(),vowel.end());
        int ind=0;
        for(int i=0;i<s.size();++i)
        {
            char c=s[i];
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
               c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
                s[i]=vowel[ind++];
        }
        return s;
    }
};