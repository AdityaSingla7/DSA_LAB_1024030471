#include <iostream>
#include <queue>
using namespace std;

class Stack1Q {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        int size = q.size();
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Popped: " << q.front() << endl;
        q.pop();
    }

    void top() {
        if (q.empty()) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Top: " << q.front() << endl;
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    Stack1Q s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.top();
    s.pop();
    s.top();
    s.pop();
    s.top();
    s.pop();
    s.pop();    

    return 0;
}