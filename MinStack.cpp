
class MinStack {
public:
    void push(int x) {
        data_.push(x);
		if (util_.empty() || util_.top() >= x) {
			util_.push(x);
		}
    }

    void pop() {
        if (!data_.empty()) {
			int x = data_.top();
			data_.pop();
			if (util_.top() == x) {
				util_.pop();
			}
		}
    }

    int top() {
        return data_.top();
    }

    int getMin() {
        return util_.top();
    }
	
private:
	stack<int> data_;
	stack<int> util_;
};