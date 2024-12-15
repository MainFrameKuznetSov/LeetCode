class Solution {
public:
    double gain(double a,double b)
    {
        return ((a+1)/(b+1))-(a/b);
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<int,int>>>pq;
        double sum=0.0;
        for(auto it:classes)
        {
            int pass=it[0],tot=it[1];
            //sum+=(double)(pass/tot);
            pq.push({gain(pass,tot),{pass,tot}});
        }

        while(extraStudents--)
        {
            auto curr=pq.top();
            pq.pop();
            int pass=curr.second.first,tot=curr.second.second;
            //sum-=(double)(pass/tot);
            ++pass;
            ++tot;
            //sum+=(double)(pass/tot);
            pq.push({gain(pass,tot),{pass,tot}});
        }

        double avg=0.0;
        while(!pq.empty())
        {
            int pass=pq.top().second.first,tot=pq.top().second.second;
            avg+=(double)pass/tot;
            pq.pop();
        }
        return avg/classes.size();
    }
};