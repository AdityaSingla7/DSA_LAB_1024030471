#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class SinglyLinkedList {
    Node* head;

public:
    SinglyLinkedList() {
        head = NULL;
    }

    // (a) Insert at beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        cout << val << " inserted at the beginning.\n";
    }

    // (b) Insert at end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << val << " inserted at the end.\n";
    }

    // (c) Insert before/after a node
    void insertBeforeAfter(int target, int val, string position) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* newNode = new Node(val);

        if (position == "before") {
            if (head->data == target) {
                insertAtBeginning(val);
                return;
            }
            Node* temp = head;
            while (temp->next != NULL && temp->next->data != target)
                temp = temp->next;
            if (temp->next == NULL) {
                cout << "Target " << target << " not found.\n";
            } else {
                newNode->next = temp->next;
                temp->next = newNode;
                cout << val << " inserted before " << target << ".\n";
            }
        } 
        else if (position == "after") {
            Node* temp = head;
            while (temp != NULL && temp->data != target)
                temp = temp->next;
            if (temp == NULL) {
                cout << "Target " << target << " not found.\n";
            } else {
                newNode->next = temp->next;
                temp->next = newNode;
                cout << val << " inserted after " << target << ".\n";
            }
        }
    }

    // (d) Delete from beginning
    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << temp->data << " deleted from beginning.\n";
        delete temp;
    }

    // (e) Delete from end
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == NULL) {
            cout << head->data << " deleted from end.\n";
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        cout << temp->next->data << " deleted from end.\n";
        delete temp->next;
        temp->next = NULL;
    }

    // (f) Delete specific node
    void deleteSpecific(int val) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node " << val << " deleted.\n";
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != val)
            temp = temp->next;
        if (temp->next == NULL) {
            cout << "Node " << val << " not found.\n";
        } else {
            Node* del = temp->next;
            temp->next = del->next;
            cout << "Node " << val << " deleted.\n";
            delete del;
        }
    }

    // (g) Search a node
    void search(int val) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == val) {
                cout << "Node " << val << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << val << " not found in list.\n";
    }

    // (h) Display all nodes
    void display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    SinglyLinkedList list;
    int choice, val, target;
    string pos;

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before/After a Node\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete Specific Node\n";
        cout << "7. Search for a Node\n";
        cout << "8. Display List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                list.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                list.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter target node value: ";
                cin >> target;
                cout << "Enter new node value: ";
                cin >> val;
                cout << "Insert before or after (type 'before' or 'after'): ";
                cin >> pos;
                list.insertBeforeAfter(target, val, pos);
                break;
            case 4:
                list.deleteFromBeginning();
                break;
            case 5:
                list.deleteFromEnd();
                break;
            case 6:
                cout << "Enter node value to delete: ";
                cin >> val;
                list.deleteSpecific(val);
                break;
            case 7:
                cout << "Enter node value to search: ";
                cin >> val;
                list.search(val);
                break;
            case 8:
                list.display();
                break;
            case 9:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 9);

    return 0;
}