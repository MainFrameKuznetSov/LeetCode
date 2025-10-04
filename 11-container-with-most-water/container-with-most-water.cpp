class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<int>vect;
        int i=0,j=height.size()-1;
        while(i<=j)
        {
            int area=min(height[i],height[j])*(j-i);
            vect.push_back(area);
            if(height[i]>height[j])
                --j;
            else
                ++i;
        }
        return *max_element(vect.begin(),vect.end());
    }
};