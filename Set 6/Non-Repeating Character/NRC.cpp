#include <iostream>
#include <vector>
using namespace std;

const int MAX_CHAR = 26;

char NRC(string &s) {
    vector<int> freq(MAX_CHAR, 0);

    for (char c : s) {
        freq[c - 'a']++;
    }

    for (int i = 0; i < s.length(); ++i) {
        if (freq[s[i] - 'a'] == 1)
            return s[i];
    }

    return '$';
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        cout << NRC(s) << endl;
    }

    return 0;
}
