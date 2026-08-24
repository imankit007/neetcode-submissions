class MinStack {
   public:
    MinStack() {}

    void push(int val) {
       st.push(val);

        int t = INT_MAX;
        if (!minSt.empty()) {
            t = minSt.top();
        }
        minSt.push(min(val, t));
    }

    void pop() {
        st.pop();
        minSt.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }

   private:
    stack<int> st;
    stack<int> minSt;
};
