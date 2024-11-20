#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class PalindromeList {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> list;
        while (head) {
            list.push_back(head->val);
            head = head->next;
        }

        int left = 0;
        int right = list.size() - 1;
        while (left < right && list[left] == list[right]) {
            left++;
            right--;
        }
        return left >= right;
    }

    static ListNode* constructLinkedList(const vector<int>& values) {
        if (values.empty()) return nullptr;
        ListNode* head = new ListNode(values[0]);
        ListNode* current = head;
        for (size_t i = 1; i < values.size(); i++) {
            current->next = new ListNode(values[i]);
            current = current->next;
        }
        return head;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); 

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);

        vector<int> values;
        int value;
        while (ss >> value) {
            values.push_back(value);
        }

        PalindromeList solution;
        ListNode* head = solution.constructLinkedList(values);
        bool result = solution.isPalindrome(head);

        cout << (result ? "Palindrome" : "Not Palindrome") << endl;

        while (head) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    return 0;
}
