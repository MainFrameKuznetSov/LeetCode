class BrowserHistory {
public:

    string home;
    stack<string>bwd,fwd;

    BrowserHistory(string homepage) {
        bwd.push(homepage);
        this->home=homepage;
    }
    
    void visit(string url) {
        while(!fwd.empty())
            fwd.pop();
        bwd.push(url);
    }
    
    string back(int steps) {
        while(steps-- && bwd.size()>1)
        {
            string node=bwd.top();
            bwd.pop();
            fwd.push(node);
        }
        return bwd.empty()?home:bwd.top();
    }
    
    string forward(int steps) {
        while(steps-- && !fwd.empty())
        {
            string node=fwd.top();
            fwd.pop();
            bwd.push(node);
        }
        return bwd.empty()?home:bwd.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */