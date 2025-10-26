#include <stack>
#include <climits>
using namespace std;

class MinStack {
public:
    stack<long long> st;
    long long num; // should be long long to match st type

    MinStack() {
        num = INT_MAX;
    }

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            num = val;
        } else if (val < num) {
            long long encoded = 2LL * val - num;
            st.push(encoded);
            num = val;
        } else {
            st.push(val);
        }
    }

    void pop() {
        if (st.empty()) return;
        long long ele = st.top();
        st.pop();
        if (ele < num) {
            num = 2 * num - ele;
        }
    }

    int top() {
        if (st.empty()) return -1;
        long long ele = st.top();
        if (ele < num) {
            return (int)num; // actual top is the current minimum
        }
        return (int)ele;
    }

    int getMin() {
        if (st.empty()) return -1;
        return (int)num;
    }
};
