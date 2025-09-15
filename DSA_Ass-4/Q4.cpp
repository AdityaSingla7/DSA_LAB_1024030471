#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeating(string s) {
    unordered_map<char,int> freq;
    queue<char> q;

    for (char ch : s) {
        freq[ch]++;
        q.push(ch);

        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (q.empty()) cout << -1 << " ";
        else cout << q.front() << " ";
    }
    cout << endl;
}

int main() {
    string s;
    cout << "Enter string (with spaces): ";
    getline(cin, s);

    string filtered = "";
    for (char c : s) if (c != ' ') filtered += c;

    firstNonRepeating(filtered);

    return 0;
}