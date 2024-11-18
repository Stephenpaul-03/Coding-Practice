#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool comparer(const string &x, const string &y) {
    return x + y > y + x;
}

string largestNumber(vector<int> &arr) {
    vector<string> strArr;
    for (int num : arr) {
        strArr.push_back(to_string(num));
    }

    sort(strArr.begin(), strArr.end(), comparer);

    string result;
    for (const string &s : strArr) {
        result += s;
    }

    if (result[0] == '0') {
        return "0";
    }

    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        cout << largestNumber(arr) << endl;
    }
    return 0;
}
