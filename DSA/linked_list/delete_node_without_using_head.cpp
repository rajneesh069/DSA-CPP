#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node) {
    while (node->next != NULL) {
        ListNode* temp = node->next;
        if (temp->next == NULL) {
            node->val = temp->val;
            node->next = NULL;
            delete temp;
            break;
        }
        int val = node->val;
        node->val = temp->val;
        node->next->val = val;
        node = node->next;
    }
}

int main() {


    return 0;
}