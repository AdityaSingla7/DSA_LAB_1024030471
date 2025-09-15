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
    void add(Sparse &s) {
        if (rows != s.rows || cols != s.cols) return;
        int i = 0, j = 0, k = 0;
        Term *sum = new Term[terms + s.terms];
        while (i < terms && j < s.terms) {
            if (data[i].row < s.data[j].row || 
               (data[i].row == s.data[j].row && data[i].col < s.data[j].col)) 
                sum[k++] = data[i++];
            else if (s.data[j].row < data[i].row || 
               (s.data[j].row == data[i].row && s.data[j].col < data[i].col)) 
                sum[k++] = s.data[j++];
            else {
                sum[k] = data[i];
                sum[k++].val = data[i++].val + s.data[j++].val;
            }
        }
        while (i < terms) sum[k++] = data[i++];
        while (j < s.terms) sum[k++] = s.data[j++];
        cout << "Addition:" << endl;
        for (int x = 0; x < k; x++)
            cout << sum[x].row << " " << sum[x].col << " " << sum[x].val << endl;
    }
};

int main() {
    int r, c, t1, t2;
    cin >> r >> c >> t1;
    Sparse s1(r, c, t1);
    s1.read();
    cin >> r >> c >> t2;
    Sparse s2(r, c, t2);
    s2.read();
    s1.add(s2);
}