class MinStack {
private:
    vector<pair<int,int>> stk;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (stk.empty()) stk.push_back({val,val});
        else {
            int curMin = stk.back().second;
            stk.push_back({val,min(val,curMin)});
        }
    }
    
    void pop() {
        stk.pop_back();
    }
    
    int top() {
        return stk.back().first;
    }
    
    int getMin() {
        return stk.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */