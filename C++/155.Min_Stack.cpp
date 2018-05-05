class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        count = 0;
        data = stack<int>();
        min = stack<int>();
    }
    
    void push(int x) {
        data.push(x); count++;
        if(min.size() == 0 || min.top() >= x) {
            min.push(x);
        }
        return;
    }
    
    void pop() {
        if(min.top() == data.top()) {
            min.pop(); data.pop();
        } else {
            data.pop();
        }
        count--;
        return;
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min.top();
    }
private:
    stack<int> data;
    stack<int> min;
    int count;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
