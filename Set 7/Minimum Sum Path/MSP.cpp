#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int helper(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
    if (i == 0 && j == 0) {
        return matrix[0][0];
    }
    if (i < 0 || j < 0) {
        return INT_MAX;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int up = matrix[i][j] + helper(i - 1, j, matrix, dp);
    int left = matrix[i][j] + helper(i, j - 1, matrix, dp);
    dp[i][j] = min(up, left);
    return dp[i][j];
}

int minSumPath(int n, int m, vector<vector<int>>& matrix) {
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return helper(n - 1, m - 1, matrix, dp);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cout << "Enter the number of rows in the matrix: ";
        cin >> n;
        cout << "Enter the number of columns in the matrix: ";
        cin >> m;

        vector<vector<int>> matrix(n, vector<int>(m));
        cout << "Enter the matrix row by row:" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> matrix[i][j];
            }
        }

        cout << "The minimum sum path is: " << minSumPath(n, m, matrix) << endl;
    }
    return 0;
}
