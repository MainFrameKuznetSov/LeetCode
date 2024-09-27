class MyCalendarTwo {
public:
    map<int,int>mp;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        ++mp[start];
        --mp[end];
        if(solve(start,end))
            return 0;
        return 1;
    }

    bool solve(int start,int end)
    {
        int common=0;
        for(auto iter:mp)
        {
            common+=iter.second;
            if(common>2)
            {
                --mp[start];
                ++mp[end];
                return 1;
            }
        }
        return 0;
    }

};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */