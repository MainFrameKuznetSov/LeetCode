class Solution {
public:
   int maxDistance(vector<vector<int>>& vect) {
       int mx=vect[0][vect[0].size()-1],mn=vect[0][0];
       int n=vect.size(),ans=0;
       for(int i=1;i<n;++i) 
       {
           ans=max({ans,vect[i][vect[i].size()-1]-mn,mx-vect[i][0]});
           mn=min(mn,vect[i][0]);
           mx=max(mx,vect[i][vect[i].size()-1]);
       }
       mn=vect[n-1][0];
       mx=vect[n-1][vect[n-1].size()-1];
       for(int i=n-2;i>=0;--i) 
       {
           ans=max({ans,vect[i][vect[i].size()-1]-mn,mx-vect[i][0]});
           mn=min(mn,vect[i][0]);
           mx=max(mx,vect[i][vect[i].size()-1]);
       }
       return ans;
   }
};