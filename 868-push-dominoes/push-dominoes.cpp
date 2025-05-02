class Solution {
public:
    string pushDominoes(string dom) {
        dom="L"+dom+"R";
        string ans;
        int left=0,n=dom.size();
        for(int right=1;right<n;++right)
        {
            if(dom[right]=='.')
                continue;
            int window=right-left-1;
            if(left)
                ans+=dom[left];
            if(dom[left]==dom[right])
                ans+=string(window,dom[left]);
            else if(dom[right]=='R' && dom[left]=='L')
                ans+=string(window,'.');
            else
                ans+=string(window/2,'R')+string(window%2,'.')+string(window/2,'L');
            left=right;
        }
        return ans;
    }
};