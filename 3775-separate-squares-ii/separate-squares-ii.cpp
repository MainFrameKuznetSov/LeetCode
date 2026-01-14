class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        set<double>ys;
        for(auto it:squares) 
        {
            double y=it[1];
            ys.insert(y);
            ys.insert(y+it[2]);
        }

        vector<double>yc(ys.begin(),ys.end());
        int m=yc.size();

        vector<vector<pair<double,double>>>add(m),rem(m);

        for(auto it:squares) 
        {
            double x1=it[0],y1=it[1],d=it[2],x2=x1+d,y2=y1+d;
            int i1=lower_bound(yc.begin(),yc.end(),y1)-yc.begin();
            int i2=lower_bound(yc.begin(),yc.end(),y2)-yc.begin();

            if(i1<i2) 
            {
                add[i1].push_back({x1,x2});
                rem[i2].push_back({x1,x2});
            }
        }

        double total=0.0;
        vector<double>pref(m, 0.0);
        multiset<pair<double,double>>act;

        for(int i=0;i+1<m;++i) 
        {
            double y1=yc[i],y2=yc[i+1],h=y2-y1;

            for(auto it:add[i]) 
                act.insert(it);
            for(auto it:rem[i]) 
            {
                auto it2=act.find(it);
                if(it2!=act.end()) 
                    act.erase(it2);
            }

            double w=0.0;
            if(!act.empty()) 
            {
                vector<pair<double,double>>iv(act.begin(), act.end());
                sort(iv.begin(),iv.end());

                double cs=iv[0].first,ce=iv[0].second;
                for(int j=1;j<(int)iv.size();++j) 
                {
                    if(iv[j].first<=ce)
                        ce=max(ce,iv[j].second);
                    else 
                    {
                        w+=ce-cs;
                        cs=iv[j].first;
                        ce=iv[j].second;
                    }
                }
                w+=ce-cs;
            }

            total+=(w*h);
            pref[i+1]=total;
        }

        double target=total/2.0;
        int idx=lower_bound(pref.begin(),pref.end(),target)-pref.begin();

        if(abs(pref[idx]-target)<1e-5)
            return yc[idx];

        double y1=yc[idx-1],y2=yc[idx],need=target-pref[idx-1];

        multiset<pair<double,double>>act2;
        for(int i=0;i<idx;++i) 
        {
            for(auto it:add[i]) 
                act2.insert(it);
            for(auto it:rem[i]) 
            {
                auto it2=act2.find(it);
                if(it2!=act2.end()) 
                    act2.erase(it2);
            }
        }

        vector<pair<double,double>>iv(act2.begin(),act2.end());
        sort(iv.begin(),iv.end());

        double w=0.0,cs=iv[0].first,ce=iv[0].second;

        for(int j=1;j<iv.size();++j) 
        {
            if(iv[j].first<=ce)
                ce=max(ce,iv[j].second);
            else 
            {
                w+=ce-cs;
                cs=iv[j].first;
                ce=iv[j].second;
            }
        }
        w+=ce-cs;
        double dy=(need/w);
        return y1+dy;
    }
};
