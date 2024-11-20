#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void Print(const vector<vector<int>>& matrix) {
    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            cout << matrix[top][i] << " ";
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            cout << matrix[i][right] << " ";
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); 

    while (t-- > 0) {
        string matrixInput;
        string line;
        while (getline(cin, line)) {
            if (line.empty()) break;
            matrixInput += line + "\n";
        }

        stringstream ss(matrixInput);
        string row;
        vector<vector<int>> matrix;

        while (getline(ss, row)) {
            stringstream rowStream(row);
            vector<int> values;
            int value;
            while (rowStream >> value) {
                values.push_back(value);
            }
            matrix.push_back(values);
        }

        Print(matrix);
    }

    return 0;
}
