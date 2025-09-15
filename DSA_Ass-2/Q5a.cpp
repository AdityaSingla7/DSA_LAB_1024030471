#include <iostream>
using namespace std;

class Diagonal {
    int *arr, n;
public:
    Diagonal(int n) {
        this->n = n;
        arr = new int[n];
    }
    void set(int i, int j, int x) {
        if (i == j) arr[i - 1] = x;
    }
    int get(int i, int j) {
        if (i == j) return arr[i - 1];
        return 0;
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Diagonal d(4);
    d.set(1,1,5); d.set(2,2,8); d.set(3,3,9); d.set(4,4,12);
    d.display();
}