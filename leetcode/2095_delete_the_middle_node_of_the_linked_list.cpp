#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* deleteMiddle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return nullptr;
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* temp = head;
    while (temp->next != slow) {
        temp = temp->next;
    }

    ListNode* next_node = slow->next;
    temp->next = next_node;
    slow->next = nullptr;
    slow = nullptr;

    return head;
}

int main() {


    return 0;
}