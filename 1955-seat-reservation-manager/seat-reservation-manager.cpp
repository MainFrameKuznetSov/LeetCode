class SeatManager {
public:
    
    priority_queue<int,vector<int>,greater<int>>pq;
    int mark;

    SeatManager(int n) {
        mark=1;
    }
    
    int reserve() {
        int seat;
        if(!pq.empty())
        {
            seat=pq.top();
            pq.pop();
            return seat;
        }
        seat=mark;
        ++mark;
        return seat;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */