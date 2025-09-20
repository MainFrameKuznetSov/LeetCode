class Router {
public:

    int SIZE;
    unordered_map<string,vector<int>>packetData;
    unordered_map<int,vector<int>>destMap;
    queue<string>Q;

    Router(int memoryLimit) {
        SIZE=memoryLimit;
    }
    
    string hashMaker(int src,int dest,int time)
    {
        return to_string(src)+"$"+to_string(dest)+"$"+to_string(time);
    }

    bool addPacket(int source, int destination, int timestamp) {
        string key=hashMaker(source,destination,timestamp);
        if(packetData.count(key))
            return false;
        if(Q.size()>=SIZE)
            forwardPacket();
        packetData[key]={source,destination,timestamp};
        Q.push(key);
        destMap[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(packetData.empty())
            return {};
        string key=Q.front();
        Q.pop();
        vector<int>packet=packetData[key];
        packetData.erase(key);
        int destination=packet[1];
        destMap[destination].erase(destMap[destination].begin());
        return packet;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto it=destMap.find(destination);
        if(it==destMap.end() || it->second.empty())
            return 0;
        vector<int>&timestamps=it->second;
        int i=lower_bound(timestamps.begin(),timestamps.end(),startTime)-timestamps.begin();
        int j=upper_bound(timestamps.begin(),timestamps.end(),endTime)-timestamps.begin();
        return j-i;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */