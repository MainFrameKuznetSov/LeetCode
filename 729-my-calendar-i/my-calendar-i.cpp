class MyCalendar {
public:
    map<int,int>mp;
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto next=mp.lower_bound(start);
        if(next!=mp.end() && next->first<end)
            return 0;
        if(next!=mp.begin() && prev(next)->second>start)
            return 0;
        mp[start]=end;
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */