#include <queue>
using namespace std;

class Stack {
private:
    queue<int> q;

public:
    Stack() {}

    void push(int val) {
        q.push(val);
    }

    void pop() {
        int size = q.size();
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }

    int top() {
        return q.back();
    }

    bool empty() {
        return q.empty();
    }
};
