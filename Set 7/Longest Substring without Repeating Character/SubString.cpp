#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int substr(const string& s) {
    int n = s.length();
    int res = 0;
    vector<int> last_index(256, -1); 
    int start = 0;

    for (int end = 0; end < n; ++end) {
        start = max(start, last_index[s[end]] + 1); 
        res = max(res, end - start + 1); 
        last_index[s[end]] = end; 
    }

    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << substr(s) << endl;
    }
    return 0;
}
