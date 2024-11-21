#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid1, int mid2, int right) {
    vector<int> temp;
    int i = left, j = mid1 + 1, k = mid2 + 1;

    while (i <= mid1 && j <= mid2 && k <= right) {
        if (arr[i] <= arr[j] && arr[i] <= arr[k]) {
            temp.push_back(arr[i++]);
        } else if (arr[j] <= arr[i] && arr[j] <= arr[k]) {
            temp.push_back(arr[j++]);
        } else {
            temp.push_back(arr[k++]);
        }
    }

    while (i <= mid1 && j <= mid2) {
        temp.push_back(arr[i] <= arr[j] ? arr[i++] : arr[j++]);
    }
    while (j <= mid2 && k <= right) {
        temp.push_back(arr[j] <= arr[k] ? arr[j++] : arr[k++]);
    }
    while (i <= mid1 && k <= right) {
        temp.push_back(arr[i] <= arr[k] ? arr[i++] : arr[k++]);
    }

    while (i <= mid1) temp.push_back(arr[i++]);
    while (j <= mid2) temp.push_back(arr[j++]);
    while (k <= right) temp.push_back(arr[k++]);

    for (int idx = 0; idx < temp.size(); ++idx) {
        arr[left + idx] = temp[idx];
    }
}

void ternarySort(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int third = (right - left) / 3;
    int mid1 = left + third;
    int mid2 = right - third;

    ternarySort(arr, left, mid1);
    ternarySort(arr, mid1 + 1, mid2);
    ternarySort(arr, mid2 + 1, right);

    merge(arr, left, mid1, mid2, right);
}

int main() {
    int t;
    cout << "Enter Test Case Count: ";
    cin >> t;

    while (t--) {
        int n;
        cout << "Enter the number of elements in the array: ";
        cin >> n;
        vector<int> arr(n);
        cout << "Enter the array elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        ternarySort(arr, 0, n - 1);

        cout << "Sorted array: ";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
