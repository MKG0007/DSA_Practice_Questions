// User function Template for C++

class Queue {
    stack<int> input, output;

  public:
    void enqueue(int x) {
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        input.push(x);
        while(!output.empty()){
            input.push(output.top());
            output.pop();
        }        
        
    }

    int dequeue() {
        if(input.empty()) return 0;
        int ele = input.top();
        input.pop();
        return ele;
    }
};