class StockPrice {
public:

    unordered_map<int,int>mp;
    priority_queue<pair<int,int>>maxHeap;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
    int latestUpdate;

    StockPrice() {
        latestUpdate=0;
    }
    
    void update(int timestamp, int price) {
        mp[timestamp]=price;
        minHeap.push({price,timestamp});
        maxHeap.push({price,timestamp});
        latestUpdate=max(latestUpdate,timestamp);
    }
    
    int current() {
        return mp[latestUpdate];
    }
    
    int maximum() {
        while(maxHeap.top().first!=mp[maxHeap.top().second])
            maxHeap.pop();
        return maxHeap.top().first;
    }
    
    int minimum() {
        while(minHeap.top().first!=mp[minHeap.top().second])
            minHeap.pop();
        return minHeap.top().first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */