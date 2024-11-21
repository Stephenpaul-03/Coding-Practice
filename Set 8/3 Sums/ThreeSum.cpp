#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool three_sum(vector<int>& arr, int s) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;
        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];
            if (sum == s) {
                cout << arr[i] << " " << arr[left] << " " << arr[right] << endl;
                return true;
            } else if (sum < s) {
                left++;
            } else {
                right--;
            }
        }
    }
    return false;
}

int main() {
    int t;
    cout << "Enter Test Case Count: ";
    cin >> t;

    while (t--) {
        int n, s;
        cout << "Enter the size of the array: ";
        cin >> n;
        vector<int> arr(n);
        cout << "Enter the array elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << "Enter the target sum: ";
        cin >> s;

        if (!three_sum(arr, s)) {
            cout << "false" << endl;
        }
    }
    return 0;
}
