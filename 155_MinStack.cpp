/*
* We maintain two stacks, one for regular push pop and other 
* for min push pop. Idea is to have min element maintained in 
* aux stack. 
* TIME: O(1) all operation.
* SPACE: O(n) for aux stack.
*/
class MinStack {
public:
    std::stack<int> st;
    std::stack<int> minst;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if (minst.empty() || val <= minst.top()){
            minst.push(val);
        }
    }
    
    void pop() {
        if (!minst.empty() && minst.top()==st.top()){
            minst.pop();
        }
        st.pop();
    }
    
    int top() {
       return st.top();
    }
    
    int getMin() {
        return minst.top();
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
