#include <iostream>
#include <vector>
using namespace std;

vector<int> bubble(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int j = 0; j < n; j++) {
            cin >> arr[j]; 
        }

        vector<int> sortedArr = bubble(arr);

        for (int j = 0; j < sortedArr.size(); j++) {
            cout << sortedArr[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
