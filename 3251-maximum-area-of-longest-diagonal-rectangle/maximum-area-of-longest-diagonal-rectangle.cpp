class Solution {
public:

    double getDiagLength(int l,int b)
    {
        return sqrt(l*l+b*b);
    }

    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxDiagonal=0;
        int maxArea=0;
        for(auto it:dimensions)
        {
            int l=it[0],b=it[1];
            double len=getDiagLength(l,b);
            if(maxDiagonal<len)
            {
                maxDiagonal=len;
                maxArea=l*b;
            }
            else if(maxDiagonal==len)
            {
                maxDiagonal=len;
                maxArea=max(maxArea,l*b);
            }
            // cout<<maxDiagonal<<" "<<maxArea<<"\n";
        }
        return maxArea;
    }
};