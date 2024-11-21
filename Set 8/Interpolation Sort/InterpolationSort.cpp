#include <iostream>
#include <vector>
using namespace std;

int interpolationIndex(vector<int>& arr, int low, int high, int key) {
    if (low <= high) {
        int pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        if (arr[pos] == key) {
            return pos;
        } else if (arr[pos] < key) {
            return interpolationIndex(arr, pos + 1, high, key);
        } else {
            return interpolationIndex(arr, low, pos - 1, key);
        }
    }
    return -1;
}

void interpolationSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int key = arr[i];
        int index = interpolationIndex(arr, i + 1, n - 1, key);
        if (index != -1 && arr[index] != key) {
            swap(arr[i], arr[index]);
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    interpolationSort(arr);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
