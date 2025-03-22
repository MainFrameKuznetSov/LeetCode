class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty())
        {
            string word=q.front().first;
            int len=q.front().second;
            q.pop();
            if(word==endWord)
                return len;
            for(int i=0;i<word.size();++i)
            {
                char prev=word[i];
                for(char ch='a';ch<='z';++ch)
                {
                    word[i]=ch;
                    if(st.count(word))
                    {
                        st.erase(word);
                        q.push({word,len+1});
                    }
                }
                word[i]=prev;
            }
        }
        return 0;
    }
};