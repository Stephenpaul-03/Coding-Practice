#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

int distance(string s1, string s2, int m, int n) {
    if (m == 0) return n;
    if (n == 0) return m;
    
    if (s1[m - 1] == s2[n - 1])
        return distance(s1, s2, m - 1, n - 1);
    
    return 1 + min({distance(s1, s2, m, n - 1),distance(s1, s2, m - 1, n),distance(s1, s2, m - 1, n - 1)});
}

int main() {
    int t;
    cin >> t; 
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        int m = s1.length();
        int n = s2.length();
        cout << distance(s1, s2, m, n) << endl;
    }
    return 0;
}
