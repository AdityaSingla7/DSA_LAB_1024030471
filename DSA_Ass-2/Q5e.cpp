#include <iostream>
using namespace std;

class Symmetric {
    int *arr, n;
public:
    Symmetric(int n) {
        this->n = n;
        arr = new int[n*(n+1)/2];
    }
    void set(int i, int j, int x) {
        if (i >= j) arr[i*(i-1)/2 + j - 1] = x;
        else arr[j*(j-1)/2 + i - 1] = x;
    }
    int get(int i, int j) {
        if (i >= j) return arr[i*(i-1)/2 + j - 1];
        return arr[j*(j-1)/2 + i - 1];
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
    Symmetric s(4);
    s.set(1,1,5); s.set(2,1,8); s.set(2,2,9); s.set(3,1,6);
    s.set(3,2,7); s.set(3,3,4); s.set(4,1,2); s.set(4,2,1);
    s.set(4,3,3); s.set(4,4,10);
    s.display();
}