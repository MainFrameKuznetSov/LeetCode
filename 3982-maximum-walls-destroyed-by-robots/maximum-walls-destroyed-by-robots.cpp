
class Robot 
{
public:
    int pos,range;
    Robot(int p,int r):pos(p),range(r){}
};

class Solution {
public:
    vector<vector<int>> dp;
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n=robots.size();
        vector<Robot>robos;
        for(int i=0;i<n;++i)
            robos.push_back({robots[i],distance[i]});

        sort(robos.begin(),robos.end(),[&](Robot a,Robot b) 
        {
            return a.pos<b.pos;
        });
        sort(walls.begin(),walls.end());
        dp.assign(n,vector<int>(2,-1));
        return solve(0,0,robos,walls);
    }

    int solve(int ind,int pre,vector<Robot>&robos,vector<int>&walls) 
    {
        if(ind==robos.size()) 
            return 0;
        if(dp[ind][pre]!=-1) 
            return dp[ind][pre];
        Robot &curr=robos[ind];
        int lb=max(0,curr.pos-curr.range);

        if(ind>0) 
        {
            if(pre==0)
                lb=max(lb,robos[ind-1].pos+1);
            else
                lb = max(lb,robos[ind-1].pos+robos[ind-1].range+1);
        }

        int leftWalls=countWalls(lb,curr.pos,walls);
        int optionLeft=leftWalls+solve(ind+1,0,robos,walls);
        int rightBound=curr.pos+curr.range;

        if(ind+1<robos.size())
            rightBound=min(rightBound,robos[ind + 1].pos-1);

        int rightWalls=countWalls(curr.pos,rightBound,walls);
        int optionRight=rightWalls+solve(ind+1,1,robos,walls);
        return dp[ind][pre]=max(optionLeft,optionRight);
    }

    int countWalls(int lb,int rb,vector<int>& walls) 
    {
        int left=lowerBound(walls,lb),right=upperBound(walls,rb);
        if(left==-1 || right==-1 || left>right)
            return 0;
        return right-left+1;
    }

    int lowerBound(vector<int>& arr,int target) 
    {
        int l=0,r=arr.size()-1;
        while(l<=r) 
        {
            int mid=l+(r-l)/2;
            if(arr[mid]>=target) 
                r=mid-1;
            else
                l=mid+1;
        }
        return l;
    }

    int upperBound(vector<int>&arr,int target) 
    {
        int l=0,r=arr.size()-1;
        while(l<=r) 
        {
            int mid=l+(r-l)/2;
            if(arr[mid]<=target) 
                l=mid+1;
            else
                r=mid-1;
        }
        return r;
    }
};