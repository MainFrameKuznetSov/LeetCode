class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left=0,right=0,gaps=0;
        for(char i:moves)
        {
            if(i=='L')
                ++left;
            else if(i=='R')
                ++right;
            else
                ++gaps;
        }
        return gaps+abs(left-right);
    }
};