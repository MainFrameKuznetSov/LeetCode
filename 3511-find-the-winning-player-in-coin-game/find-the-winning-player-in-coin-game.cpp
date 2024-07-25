class Solution {
public:
    string losingPlayer(int x, int y) {
        int cnt=0;
        while(x>0 && y>3)
        {
            ++cnt;
            x-=1;
            y-=4;
        }
        if(cnt&1)
            return "Alice";
        else
            return "Bob";
    }
};