class Solution {
public:

    string helper(string word)
    {
        sort(word.begin(),word.end());
        return word;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        ans.push_back(words[0]);
        string pre=helper(words[0]);
        for(int i=1;i<words.size();++i)
        {
            string cur=helper(words[i]);
            if(cur!=pre)
            {
                ans.push_back(words[i]);
                pre=cur;
            }
        }
        return ans;
    }
};