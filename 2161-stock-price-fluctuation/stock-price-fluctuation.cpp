class StockPrice {
public:

    multiset<int>prices;
    map<int,int>mp;

    StockPrice() {
        prices.clear();
        mp.clear();
    }
    
    void update(int timestamp, int price) {
        if(mp.count(timestamp))
        {
            int value=mp[timestamp];
            prices.erase(prices.find(value));
        }
        mp[timestamp]=price;
        prices.insert(price);
    }
    
    int current() {
        return mp.rbegin()->second;
    }
    
    int maximum() {
        return *prices.rbegin();
    }
    
    int minimum() {
        return *prices.begin();
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