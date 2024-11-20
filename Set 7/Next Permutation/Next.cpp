#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void permutation(vector<int>& arr) {
    int n = arr.size();
    int pivot = -1;

    for (int i = n - 2; i >= 0; --i) {
        if (arr[i] < arr[i + 1]) {
            pivot = i;
            break;
        }
    }

    if (pivot == -1) {
        reverse(arr.begin(), arr.end());
        return;
    }

    for (int i = n - 1; i > pivot; --i) {
        if (arr[i] > arr[pivot]) {
            swap(arr[i], arr[pivot]);
            break;
        }
    }
    reverse(arr.begin() + pivot + 1, arr.end());
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

        permutation(arr);

        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
