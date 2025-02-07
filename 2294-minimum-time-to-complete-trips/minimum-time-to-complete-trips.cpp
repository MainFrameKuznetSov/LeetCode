class Solution {
public:

    bool solve(long long mid,vector<int>& time, int totalTrips){
      long long cnt=0;
      for(auto it : time){
        long long temp = mid/it;
        cnt+=temp;
      }
      return cnt>=totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 1;
        long long high = 1e14;
        while(low<high){
            long long mid=low+(high-low)/2;
            if(solve(mid,time,totalTrips)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};