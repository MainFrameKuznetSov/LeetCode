class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int>cA(7),cB(7),sem(7);
        int n=tops.size();
        for(int i=0;i<n;++i)
        {
            ++cA[tops[i]];
            ++cB[bottoms[i]];
            if(tops[i]==bottoms[i])
                ++sem[tops[i]];
        }
        for(int i=1;i<7;++i)
        {
            if(cA[i]+cB[i]==n+sem[i])
                return n-max(cA[i],cB[i]);
        }
        return -1;
    }
};