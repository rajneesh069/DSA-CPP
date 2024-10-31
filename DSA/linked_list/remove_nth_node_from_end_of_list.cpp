#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == nullptr || (head->next == nullptr && n == 1)) return nullptr;
    ListNode* prev = nullptr;
    ListNode* slow = head;
    ListNode* fast = head;

    while (n--) {
        fast = fast->next;
    }

    while (fast) {
        fast = fast->next;
        prev = slow;
        slow = slow->next;
    }

    if (!prev) {
        ListNode* current = head;
        head = head->next;
        current->next = nullptr;
        delete current;
        return head;
    }

    ListNode* next_node = slow->next;
    prev->next = next_node;
    slow->next = nullptr;
    slow = nullptr;

    return head;
}

int main() {


    return 0;
}