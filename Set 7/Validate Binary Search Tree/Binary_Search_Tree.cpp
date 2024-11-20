#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <vector>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

int maxValue(Node* node) {
    if (node == nullptr)
        return INT_MIN;
    return max(node->data, max(maxValue(node->left), maxValue(node->right)));
}

int minValue(Node* node) {
    if (node == nullptr)
        return INT_MAX;
    return min(node->data, min(minValue(node->left), minValue(node->right)));
}

bool checker(Node* node) {
    if (node == nullptr)
        return true;

    if (node->left && maxValue(node->left) >= node->data)
        return false;

    if (node->right && minValue(node->right) <= node->data)
        return false;

    return checker(node->left) && checker(node->right);
}

Node* build(const vector<string>& values) {
    if (values.empty() || values[0] == "N")
        return nullptr;

    Node* root = new Node(stoi(values[0]));
    queue<Node*> q;
    q.push(root);

    size_t index = 1;
    while (index < values.size()) {
        Node* current = q.front();
        q.pop();

        if (values[index] != "N") {
            current->left = new Node(stoi(values[index]));
            q.push(current->left);
        }
        index++;

        if (index >= values.size())
            break;

        if (values[index] != "N") {
            current->right = new Node(stoi(values[index]));
            q.push(current->right);
        }
        index++;
    }

    return root;
}

int main() {
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;
    cin.ignore(); 

    for (int i = 1; i <= t; i++) {
        cout << "\nTest case " << i << ":\n";
        cout << "Enter level-order traversal (use 'N' for null nodes): ";
        
        string inputLine;
        getline(cin, inputLine);
        stringstream ss(inputLine);

        vector<string> level_order;
        string token;
        while (ss >> token) {
            level_order.push_back(token);
        }

        Node* tree_root = build(level_order);

        if (checker(tree_root)) {
            cout << "This tree satisfies the Binary Search Tree (BST) property.\n";
        } else {
            cout << "This tree does NOT satisfy the BST property.\n";
        }
    }

    return 0;
}
