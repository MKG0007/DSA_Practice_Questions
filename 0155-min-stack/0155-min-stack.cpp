class MinStack {
public:
    stack<long long int> st;
    long long int minele;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            minele = val;
            return;
        }
        if(val<minele){
            st.push(((long long int)2*val - minele));
            minele = val;
        }
        else{
            st.push(val);
        }
    }
    
    void pop() {

        if(st.top()<minele){
            minele = 2*minele - st.top();
        }
        st.pop();
        
    }
    
    int top() {

        if(st.top()<minele){
            return minele;
        }
        else{
            return st.top();
        }
        
    }
    
    int getMin() {
        return minele;
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