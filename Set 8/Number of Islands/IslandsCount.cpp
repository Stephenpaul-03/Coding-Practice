#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& grid, int i, int j, int n, int m) {
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0) {
        return;
    }
    grid[i][j] = 0; 
    dfs(grid, i + 1, j, n, m); 
    dfs(grid, i - 1, j, n, m); 
    dfs(grid, i, j + 1, n, m); 
    dfs(grid, i, j - 1, n, m); 
    dfs(grid, i + 1, j + 1, n, m); 
    dfs(grid, i - 1, j - 1, n, m); 
    dfs(grid, i + 1, j - 1, n, m); 
    dfs(grid, i - 1, j + 1, n, m); 
}

int countIslands(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 1) {
                count++;
                dfs(grid, i, j, n, m); 
            }
        }
    }

    return count;
}

int main() {
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;

    while (t--) {
        int n, m;
        cout << "Enter dimensions of the grid (rows and columns): ";
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        cout << "Enter the grid (0s and 1s):\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }

        cout << "Number of islands: " << countIslands(grid) << endl;
    }

    return 0;
}
