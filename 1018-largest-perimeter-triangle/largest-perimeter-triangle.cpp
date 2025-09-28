class Solution {
public:

    bool isTriangle(int a,int b,int c)
    {
        return (a+b>c && b+c>a && c+a>b);
    }

    int largestPerimeter(vector<int>& nums) {
        int n=nums.size(),maxPeri=0;
        sort(nums.begin(),nums.end());
        for(int i=n-1;i>=2;--i)
        {
            int a=nums[i],b=nums[i-1],c=nums[i-2];
            if(isTriangle(a,b,c))
                maxPeri=max(maxPeri,a+b+c);
        }
        return maxPeri;
    }
};