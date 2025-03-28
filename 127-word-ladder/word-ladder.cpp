class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty())
        {
            string node=q.front().first;
            int len=q.front().second;
            q.pop();
            if(node==endWord)
                return len;
            for(int i=0;i<node.size();++i)
            {
                char pre=node[i];
                for(char ch='a';ch<='z';++ch)
                {
                    node[i]=ch;
                    if(st.count(node))
                    {
                        //node.push_back(last);
                        q.push({node,len+1});
                        st.erase(node);
                        //break;
                    }
                }
                node[i]=pre;
            }
        }
        return 0;
    }
};