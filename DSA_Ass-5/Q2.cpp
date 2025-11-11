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

    // Insert at end (to easily build the list)
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
    }

    // Display the linked list
    void display() {
        if (head == NULL) {
            cout << "List is empty.";
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL)
                cout << "->";
            temp = temp->next;
        }
        cout << endl;
    }

    // Count and delete all occurrences of a key
    int deleteOccurrences(int key) {
        int count = 0;

        // Delete from beginning if head contains key
        while (head != NULL && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            count++;
        }

        // Delete occurrences from the rest of the list
        Node* current = head;
        while (current != NULL && current->next != NULL) {
            if (current->next->data == key) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                count++;
            } else {
                current = current->next;
            }
        }

        return count;
    }
};

int main() {
    SinglyLinkedList list;

    // Create the linked list: 1->2->1->2->1->3->1
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    list.insertAtEnd(3);
    list.insertAtEnd(1);

    cout << "Original Linked List: ";
    list.display();

    int key = 1;
    int count = list.deleteOccurrences(key);

    cout << "Count: " << count << endl;
    cout << "Updated Linked List: ";
    list.display();

    return 0;
}