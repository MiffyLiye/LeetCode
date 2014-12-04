#include <stack>
#include <multiset>

using namespace std;

class MinStack {
public:
    void push(int x) {
        mini_stack_push(x);
    }

    void pop() {
        mini_stack_pop();
    }

    int top() {
        return mini_stack_top();
    }

    int getMin() {
        return mini_stack_min();
    }
private:
    stack<int> elements_;
    stack<int> current_minimum_;
    stack<int> time_to_change_minimum_;

    void mini_stack_push(int x) {
        elements_.push(x);
        if (current_minimum_.empty() || x < current_minimum_.top()) {
            current_minimum_.push(x);
            time_to_change_minimum_.push(1);
        }
        else {
            auto times = time_to_change_minimum_.top();
            time_to_change_minimum_.pop();
            time_to_change_minimum_.push(times + 1);
        }
    }

    void mini_stack_pop() {
        elements_.pop();
        auto times = time_to_change_minimum_.top();
        if (times == 1) {
            current_minimum_.pop();
            time_to_change_minimum_.pop();
        }
        else {
            time_to_change_minimum_.pop();
            time_to_change_minimum_.push(times - 1);
        }
    }

    int mini_stack_top() {
        return elements_.top();
    }

    int mini_stack_min() {
        return current_minimum_.top();
    }
};