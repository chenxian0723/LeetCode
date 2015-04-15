class MinStack {
public:
    stack<int> s1;
    stack<int> s2;

    void push(int x) {
        if(s1.empty())
            s2.push(x);
        else
            s2.push(min(x,s2.top()));       //s2栈记录到当前位置时的最小值
        s1.push(x);
    }

    void pop() {
        s1.pop();
        s2.pop();
    }

    int top() {
        return s1.top();
    }

    int getMin() {
        return s2.top();
    }
};
