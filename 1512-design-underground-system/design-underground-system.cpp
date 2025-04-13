class UndergroundSystem {
public:

    map<int,pair<string,int>>In;
    map<pair<string,string>,pair<int,int>>real;

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string u, int t) {
        In[id]={u,t};
    }
    
    void checkOut(int id, string v, int t) {
        int tIn;
        string u;
        if(In.count(id))
        {
            u=In[id].first;
            tIn=In[id].second;
            In.erase(id);
        }
        // if(v<u)
        //     swap(u,v);
        if(!real.count({u,v}))
            real[{u,v}]={t-tIn,1};
        else
        {
            real[{u,v}].first+=(t-tIn);
            real[{u,v}].second+=1;
        }
        cout<<real[{u,v}].first<<" "<<real[{u,v}].second<<"\n";
        //cout<<"Station "<<u<<" to "<<v<<" in "<<tIn<<" to "<<t<<"\n";
    }
    
    double getAverageTime(string u, string v) {
        // if(v<u)
        //     swap(u,v);
        //cout<<real[{u,v}].first<<" to "<<real[{u,v}].second<<"\n";
        return ((double)real[{u,v}].first/(double)real[{u,v}].second);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */