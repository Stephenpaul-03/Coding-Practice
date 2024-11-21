#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagrams;
    for (const string& str : strs) {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());
        anagrams[sortedStr].push_back(str);
    }
    vector<vector<string>> result;
    for (auto& entry : anagrams) {
        result.push_back(entry.second);
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> strs(n);
        for (int i = 0; i < n; i++) {
            cin >> strs[i];
        }
        vector<vector<string>> result = groupAnagrams(strs);
        for (const auto& group : result) {
            for (const string& str : group) {
                cout << str << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
