#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

int element_finder(vector<int> &arr, int n) {
    priority_queue<int> maxHeap;

    for (int num : arr) {
        maxHeap.push(num);
        if (maxHeap.size() > n) {
            maxHeap.pop();
        }
    }
    return maxHeap.top();
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        int n;
        cin >> n;
        cin.ignore();
        cout << element_finder(arr, n) << endl;
    }
    return 0;
}
