class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> dir = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        string target = "123450";
        set<string>st;
        queue<string>q;
        string start="";
        for(auto row:board) 
        {
            for(auto col:row)
                start+=col+'0';
        }
        q.push(start);
        st.insert(start);
        int ans=0;
        while(!q.empty()) 
        {
            int size=q.size();
            while(size--) 
            {
                string top=q.front();
                q.pop();
                if(top==target) 
                    return ans;
                int zero=top.find('0');
                for(auto move:dir[zero]) 
                {
                    string next=top;
                    swap(next[move],next[zero]);
                    if(!st.count(next)) 
                    {
                        st.insert(next);
                        q.push(next);
                    }
                }
            }
            ++ans;
        }
        return -1;
    }
};