#include <iostream>
using namespace std;

class UpperTri {
    int *arr, n;
public:
    UpperTri(int n) {
        this->n = n;
        arr = new int[n*(n+1)/2];
    }
    void set(int i, int j, int x) {
        if (i <= j) arr[j*(j-1)/2 + i - 1] = x;
    }
    int get(int i, int j) {
        if (i <= j) return arr[j*(j-1)/2 + i - 1];
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
    UpperTri u(4);
    u.set(1,1,5); u.set(1,2,8); u.set(1,3,6); u.set(1,4,2);
    u.set(2,2,9); u.set(2,3,7); u.set(2,4,1);
    u.set(3,3,4); u.set(3,4,3);
    u.set(4,4,10);
    u.display();
}