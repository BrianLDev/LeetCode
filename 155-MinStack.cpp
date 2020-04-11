/*
Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/

#include <iostream>
#include <vector>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> stack;
    int min;

    MinStack() {
        min = INT_MAX;
    }
    
    // in this vector, back == top of stack, front == bottom of stack

    void push(int x) {
        stack.push_back(x);
        if (x < min) { min = x; }
    }
    
    void pop() {
        if (stack.size() <= 0) { return; }
        else {
            int x = stack.back();
            stack.pop_back();
            if (x == min) { findNewMin(); }
        }
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return min;    
    }

    void findNewMin() {
        min = INT_MAX;
        for (int n : stack) {
            if (n < min) { min = n; }
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    #include <iostream>

    using namespace std;

    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << "** GET MIN: " << obj->getMin() << endl;
    obj->pop();
    cout << "** GET TOP: " << obj->top() << endl;
    cout << "** GET MIN: " << obj->getMin() << endl;

    return 0;
}