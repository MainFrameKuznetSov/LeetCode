class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<pair<double,double>>events;
        double total=0;
        for(auto it:squares)
        {
            double y=it[1],l=it[2];
            events.push_back({y,l});
            events.push_back({y+l,-l});
            total+=l*l;
        }
        sort(events.begin(),events.end());
        double cur=0,area=0;
        for(int i=0;i+1<events.size();i++)
        {
            cur+=events[i].second;
            double dy=events[i+1].first-events[i].first;
            if(area+cur*dy>=total/2)
                return events[i].first+(total/2-area)/cur;
            area+=cur*dy;
        }
        return events.back().first;
    }
};
