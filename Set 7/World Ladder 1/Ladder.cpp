#include <iostream>
#include <unordered_set>
#include <queue>
#include <string>
#include <iterator>
using namespace std;

int ladder(string start, string target, unordered_set<string>& D) {
    if (start == target) {
        return 0;
    }
    if (D.find(target) == D.end()) {
        return 0;
    }

    int level = 0;
    int wordLength = start.length();
    queue<string> Q;
    Q.push(start);

    while (!Q.empty()) {
        level++;
        int size = Q.size();

        for (int i = 0; i < size; i++) {
            string word = Q.front();
            Q.pop();

            for (int pos = 0; pos < wordLength; pos++) {
                char origChar = word[pos];

                for (char c = 'a'; c <= 'z'; c++) {
                    word[pos] = c;

                    if (word == target) {
                        return level + 1;
                    }

                    if (D.find(word) != D.end()) {
                        D.erase(word);
                        Q.push(word);
                    }
                }

                word[pos] = origChar;
            }
        }
    }

    return 0;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        unordered_set<string> D;
        string word;
        string start, end;
        
        while (cin >> word) {
            if (word == "-1") break;
            D.insert(word);
        }
        
        cin >> start >> end;
        
        cout << ladder(start, end, D) << endl;
    }

    return 0;
}
