#include <iostream>
using namespace std;

struct Term {
    int row, col, val;
};

class Sparse {
    int rows, cols, terms;
    Term *data;
public:
    Sparse(int r, int c, int t) {
        rows = r; cols = c; terms = t;
        data = new Term[t];
    }
    void read() {
        for (int i = 0; i < terms; i++)
            cin >> data[i].row >> data[i].col >> data[i].val;
    }
    void transpose() {
        Term *tdata = new Term[terms];
        int k = 0;
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < terms; j++) {
                if (data[j].col == i) {
                    tdata[k].row = data[j].col;
                    tdata[k].col = data[j].row;
                    tdata[k].val = data[j].val;
                    k++;
                }
            }
        }
        cout << "Transpose:" << endl;
        for (int i = 0; i < terms; i++)
            cout << tdata[i].row << " " << tdata[i].col << " " << tdata[i].val << endl;
    }
};

int main() {
    int r, c, t;
    cin >> r >> c >> t;
    Sparse s(r, c, t);
    s.read();
    s.transpose();
}