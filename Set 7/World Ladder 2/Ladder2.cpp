#include <iostream>
#include <unordered_set>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

class Node {
public:
    string word;
    int len;
    Node(string w, int l) : word(w), len(l) {}
};

bool isAdj(const string &a, const string &b) {
    int count = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            count++;
        }
    }
    return count == 1;
}

int ladderLength(string beginWord, string endWord, unordered_set<string> &wordList) {
    if (wordList.find(endWord) == wordList.end()) return 0;

    queue<Node> q1, q2;
    unordered_map<string, int> vis1, vis2;

    q1.push(Node(beginWord, 1));
    q2.push(Node(endWord, 1));
    vis1[beginWord] = 1;
    vis2[endWord] = 1;

    while (!q1.empty() && !q2.empty()) {
        Node curr1 = q1.front(); q1.pop();
        Node curr2 = q2.front(); q2.pop();

        for (const string &it : wordList) {
            if (isAdj(curr1.word, it) && vis1.find(it) == vis1.end()) {
                Node temp(it, curr1.len + 1);
                q1.push(temp);
                vis1[it] = curr1.len + 1;
                if (temp.word == endWord) return temp.len;
                if (vis2.find(temp.word) != vis2.end()) return temp.len + vis2[temp.word] - 1;
            }
        }

        for (const string &it : wordList) {
            if (isAdj(curr2.word, it) && vis2.find(it) == vis2.end()) {
                Node temp(it, curr2.len + 1);
                q2.push(temp);
                vis2[it] = curr2.len + 1;
                if (temp.word == beginWord) return temp.len;
                if (vis1.find(temp.word) != vis1.end()) return temp.len + vis1[temp.word] - 1;
            }
        }
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        unordered_set<string> wordList;
        string word;
        while (cin >> word) {
            if (word == "-1") break;
            wordList.insert(word);
        }
        string start, end;
        cin >> start >> end;
        cout << ladderLength(start, end, wordList) << endl;
    }
    return 0;
}
