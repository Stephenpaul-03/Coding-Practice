#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int min(int x, int y, int z) {
    if (x < y)
        return (x < z) ? x : z;
    else
        return (y < z) ? y : z;
}

int minCost(vector<vector<int>>& cost, int m, int n) {
    if (m < 0 || n < 0)
        return INT_MAX;
    else if (m == 0 && n == 0)
        return cost[m][n];
    else
        return cost[m][n] + min(minCost(cost, m - 1, n - 1),
                                minCost(cost, m - 1, n),
                                minCost(cost, m, n - 1));
}

int main() {
    int T;
    cout << "Enter the number of test cases: ";
    cin >> T;

    while (T--) {
        int R, C;
        cout << "Enter the number of rows and columns: ";
        cin >> R >> C;

        vector<vector<int>> cost(R, vector<int>(C));
        cout << "Enter the cost matrix row by row:\n";
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                cin >> cost[i][j];
            }
        }

        int m, n;
        cout << "Enter the target cell indices (m, n): ";
        cin >> m >> n;

        cout << "Minimum cost to reach (" << m << ", " << n << "): " << minCost(cost, m, n) << endl;
    }

    return 0;
}
