class Solution {
public:

    double getLength(int l,int b)
    {
        return sqrt(l*l+b*b);
    }

    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxDiagonal=0;
        int maxArea=0;
        for(auto it:dimensions)
        {
            int l=it[0],b=it[1];
            if(maxDiagonal<getLength(l,b))
            {
                maxDiagonal=getLength(l,b);
                maxArea=l*b;
            }
            else if(maxDiagonal==getLength(l,b))
            {
                maxDiagonal=getLength(l,b);
                maxArea=max(maxArea,l*b);
            }
            // cout<<maxDiagonal<<" "<<maxArea<<"\n";
        }
        return maxArea;
    }
};