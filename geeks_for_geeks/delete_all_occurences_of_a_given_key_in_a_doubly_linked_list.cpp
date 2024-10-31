#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
    Node(int x) { data = x; next = prev = NULL; }
};

void deleteAllOccurOfX(struct Node** head_ref, int x) {
    if (*head_ref == nullptr) return;

    Node* temp = *head_ref;
    while (temp) {
        if (temp->data == x) {
            Node* current_node = temp;
            Node* next_node = current_node->next;
            Node* prev_node = current_node->prev;

            if (current_node == *head_ref) {
                *head_ref = next_node;
                if (next_node) next_node->prev = nullptr;
            } else {
                if (next_node)next_node->prev = prev_node;
                if (prev_node)prev_node->next = next_node;
            }

            temp = next_node;
            current_node->next = nullptr;
            current_node->prev = nullptr;
            current_node = nullptr;
        } else {
            temp = temp->next;
        }
    }
}


int main() {


    return 0;
}