class MinStack {
private:
    priority_queue<int,vector<int>,greater<int>> pq, pqErase;
    vector<int> stk;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push_back(val);
        pq.push(val);
    }
    
    void pop() {
        pqErase.push(stk.back());
        while (!pqErase.empty() && pq.top() == pqErase.top()) {
            pq.pop();
            pqErase.pop();
        }
        stk.pop_back();
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        return pq.top();
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