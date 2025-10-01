class CustomStack {
private:
    vector<int> stack;
    vector<int> inc;
    int maxSize;

public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }

    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);
            inc.push_back(0);
        }
    }

    int pop() {
        if (stack.empty()) return -1;

        int i = stack.size() - 1;
        int res = stack.back() + inc[i];
        stack.pop_back();
        if (!inc.empty()) {
            if (i > 0) inc[i - 1] += inc[i];
            inc.pop_back();
        }
        return res;
    }

    void increment(int k, int val) {
        int n = min(k, (int)stack.size());
        if (n > 0) {
            inc[n - 1] += val;
        }
    }
};
