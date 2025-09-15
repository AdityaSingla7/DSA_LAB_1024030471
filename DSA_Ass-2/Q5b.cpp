#include <iostream>
using namespace std;

class TriDiagonal {
    int *arr, n;
public:
    TriDiagonal(int n) {
        this->n = n;
        arr = new int[3*n - 2];
    }
    void set(int i, int j, int x) {
        if (i - j == 0) arr[n - 1 + i - 1] = x;
        else if (i - j == 1) arr[i - 2] = x;
        else if (j - i == 1) arr[2*n - 1 + i - 1] = x;
    }
    int get(int i, int j) {
        if (i - j == 0) return arr[n - 1 + i - 1];
        else if (i - j == 1) return arr[i - 2];
        else if (j - i == 1) return arr[2*n - 1 + i - 1];
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
    TriDiagonal t(4);
    t.set(1,1,5); t.set(1,2,8); t.set(2,1,3); t.set(2,2,9);
    t.set(2,3,6); t.set(3,2,7); t.set(3,3,4); t.set(3,4,2);
    t.set(4,3,1); t.set(4,4,10);
    t.display();
}