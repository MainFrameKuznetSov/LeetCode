class Solution {
public:
    bool judgeCircle(string moves) {
        int distX=0,distY=0;
        for(char c:moves)
        {
            if(c=='U')
                ++distY;
            else if(c=='D')
                --distY;
            else if(c=='R')
                ++distX;
            else 
                --distX;
        }
        return (distX==0 && distY==0);
    }
};