class Solution {
public:
    int helper(vector<int>& h) {
        stack<int>st;
        int maxArea=0;
        h.push_back(0);
        for(int i=0;i<h.size();++i) 
        {
            while(!st.empty() && h[st.top()]>h[i]) 
            {
                int hgt=h[st.top()];
                st.pop();
                int width=st.empty()?i:i-st.top()-1;
                maxArea=max(maxArea,hgt*width);
            }
            st.push(i);
        }
        h.pop_back();
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<int>hist(m,0);
        int ans=0;
        for(int i=0;i<n;++i) 
        {
            for(int j=0;j<m;++j) 
            {
                if(matrix[i][j]=='1')
                    ++hist[j];
                else
                    hist[j]=0;
            }
            ans=max(ans,helper(hist));
        }
        return ans;
    }
};
