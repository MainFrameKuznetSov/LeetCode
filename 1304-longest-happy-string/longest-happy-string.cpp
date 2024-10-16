class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a) 
            pq.push({a,'a'});
        if(b) 
            pq.push({b,'b'});
        if(c) 
            pq.push({c,'c'});
        string result="";
        while (!pq.empty())
        {
            auto temp=pq.top();
            pq.pop();
            if(result.size()>=2 && result.back()==temp.second && result[result.size()-2]==temp.second) 
            {
                if(pq.empty()) 
                    break;
                auto iter=pq.top();
                pq.pop();
                result+=iter.second;
                --iter.first;
                if(iter.first>0) 
                    pq.push(iter);
                pq.push(temp);
            } 
            else
            {
                result+=temp.second;
                --temp.first;
                if(temp.first>0) 
                    pq.push(temp);
            }
        }
        return result;
    }
};