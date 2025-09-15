#include <iostream>
using namespace std;

class LowerTri {
    int *arr, n;
public:
    LowerTri(int n) {
        this->n = n;
        arr = new int[n*(n+1)/2];
    }
    void set(int i, int j, int x) {
        if (i >= j) arr[i*(i-1)/2 + j - 1] = x;
    }
    int get(int i, int j) {
        if (i >= j) return arr[i*(i-1)/2 + j - 1];
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
    LowerTri l(4);
    l.set(1,1,5); l.set(2,1,8); l.set(2,2,9);
    l.set(3,1,6); l.set(3,2,7); l.set(3,3,4);
    l.set(4,1,2); l.set(4,2,1); l.set(4,3,3); l.set(4,4,10);
    l.display();
}