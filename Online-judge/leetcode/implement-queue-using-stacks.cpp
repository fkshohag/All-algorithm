# include <bits/stdc++.h>
using namespace std;

/**
 * @author Md.Shohag <shohag.fks@gmail.com>
 * Problem : https://leetcode.com/problems/implement-queue-using-stacks/description/
 * Time complexity : O(N) where N is the size of stack.
 * Space complexity : O(N) since we are not consuming additional space 
*/


class MyQueue {
private:
    stack<int> input, output;
public:
    MyQueue() {

    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int x = peek();
        output.pop();
        return x;
    }
    
    int peek() {
        if (output.empty()) {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */