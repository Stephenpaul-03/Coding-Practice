#include <iostream>
#include <vector>
using namespace std;

class Pair {
public:
    int first, second;
    Pair(int f, int s) : first(f), second(s) {}
};

vector<vector<int>> define(int tasks, const vector<Pair>& pre) {
    vector<vector<int>> graph(tasks);
    for (const auto& p : pre) {
        graph[p.second].push_back(p.first);
    }
    return graph;
}

bool dfs(const vector<vector<int>>& graph, int node, vector<bool>& onpath, vector<bool>& visited) {
    if (visited[node]) {
        return false;
    }
    onpath[node] = visited[node] = true;
    for (int neigh : graph[node]) {
        if (onpath[neigh] || dfs(graph, neigh, onpath, visited)) {
            return true;
        }
    }
    return false;
}

bool finish(int tasks, const vector<Pair>& pre) {
    vector<vector<int>> graph = define(tasks, pre);
    vector<bool> onpath(tasks, false);
    vector<bool> visited(tasks, false);
    for (int i = 0; i < tasks; ++i) {
        if (!visited[i] && dfs(graph, i, onpath, visited)) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int numTasks, numPrerequisites;
        cin >> numTasks >> numPrerequisites;
        vector<Pair> prerequisites;
        for (int i = 0; i < numPrerequisites; ++i) {
            int first, second;
            cin >> first >> second;
            prerequisites.push_back(Pair(first, second));
        }
        
        if (finish(numTasks, prerequisites)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
