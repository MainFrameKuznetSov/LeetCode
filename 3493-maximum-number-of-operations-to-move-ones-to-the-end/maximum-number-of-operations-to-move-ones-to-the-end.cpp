class Solution {
public:
    int maxOperations(string s) {
        int ans=0,one=0;
        bool flag=1;
        for(char ch:s)
        {
            if(ch=='1')
            {
                ++one;
                flag=1;
            }
            else
            {
                if(flag)
                    ans+=one;
                flag=0;
            }
        }
        return ans;
    }
};