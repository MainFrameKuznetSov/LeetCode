class SeatManager {
public:
    set<int>res,unres;
    SeatManager(int n) {
        for(int i=1;i<=n;++i)
            unres.insert(i);
    }
    
    int reserve() {
        int seat=*unres.begin();
        unres.erase(seat);
        res.insert(seat);
        return seat;
    }
    
    void unreserve(int seatNumber) {
        unres.insert(seatNumber);
        res.erase(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */