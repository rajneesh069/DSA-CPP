#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


Node* addOne(Node* head) {
    if (!head) return nullptr;
    Node* temp = head;
    int l = 0, ct = 0;
    while (temp->next) {
        if (temp->data == 9) ct++;
        else ct = 0;
        l++;
        temp = temp->next;
    }
    l++;
    // 4 5 9 7 9 9 9
    if (temp->data < 9) {
        temp->data += 1;
        return head;
    }

    // it means last element is 9 for sure at this point
    ct++;

    temp = head;
    int diff = l - ct;

    // what if all are 9?
    if (diff == 0) {
        Node* new_node = new Node(1);
        Node* temp = head;
        new_node->next = head;
        while (temp) {
            temp->data = 0;
            temp = temp->next;
        }
        head = new_node;
        return head;
    }

    // now there are less 9's than the total length
    while (--diff) {
        temp = temp->next;
    }
    temp->data += 1;
    while (temp) {
        temp = temp->next;
        if (temp) temp->data = 0;
    }
    return head;

}


int main() {


    return 0;
}