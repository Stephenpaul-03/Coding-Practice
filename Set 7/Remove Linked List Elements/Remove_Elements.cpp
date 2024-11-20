#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

Node* del(Node* head, int key) {
    Node* curr = head;
    Node* prev = nullptr;

    while (curr != nullptr) {
        if (curr->data == key) {
            if (prev == nullptr) {
                head = curr->next; 
            } else {
                prev->next = curr->next;
            }
            Node* temp = curr;
            curr = curr->next; 
            delete temp;       
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

Node* build(const vector<int>& values) {
    if (values.empty()) return nullptr;

    Node* head = new Node(values[0]);
    Node* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new Node(values[i]);
        current = current->next;
    }
    return head;
}

void print(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) cout << " -> ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;
    cin.ignore(); 

    for (int i = 1; i <= t; ++i) {
        cout << "\nTest case " << i << ":" << endl;
        cout << "Enter the elements of the linked list (space-separated): ";
        string inputLine;
        getline(cin, inputLine);
        stringstream ss(inputLine);
        vector<int> values;
        int value;
        while (ss >> value) {
            values.push_back(value);
        }

        Node* head = build(values);

        cout << "Enter the value to delete from the linked list: ";
        int key;
        cin >> key;
        cin.ignore();

        cout << "Original Linked List: ";
        print(head);
        head = del(head, key);

        cout << "Updated Linked List after deletion: ";
        print(head);
    }

    return 0;
}
