#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;

    ListNode* temp = head;
    ListNode* even_linked_list = nullptr;
    ListNode* odd_linked_list = nullptr;
    bool alternate_bw_even_odd = true;
    ListNode* odd_head = nullptr;
    ListNode* even_head = nullptr;

    while (temp) {
        if (alternate_bw_even_odd) {
            if (!odd_linked_list) {
                odd_linked_list = temp;
                odd_head = odd_linked_list;
            } else {
                odd_linked_list->next = temp;
                odd_linked_list = odd_linked_list->next;
            }

            temp = temp->next;
            alternate_bw_even_odd = false;
        } else {
            if (!even_linked_list) {
                even_linked_list = temp;
                even_head = even_linked_list;
            } else {
                even_linked_list->next = temp;
                even_linked_list = even_linked_list->next;
            }

            temp = temp->next;
            alternate_bw_even_odd = true;
        }
    }

    odd_linked_list->next = even_head;
    even_linked_list->next = nullptr;

    return odd_head;
}

int main() {


    return 0;
}