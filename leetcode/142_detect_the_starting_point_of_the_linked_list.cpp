#include <bits/stdc++.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
    // Space Complexity: O(N)
    // Time Complexity: O(N)
private:
    bool isCycle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL){
            
            fast = fast->next;
            if(fast) fast = fast->next;
            else return false;
            slow = slow->next;

             if(fast==slow){
                return true;
            }
        }

        return false;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        if(isCycle(head)){
            unordered_map<ListNode*, int>m;
            ListNode* temp = head;
            while(true){
                if(m.find(temp) == m.end()){
                    m[temp] = 1;
                    temp = temp->next;
                }else {
                    return temp;
                }
            }
        }
        return NULL;
    }
};


    // Optimized Approach
    // Space compelxity: O(1)
    // Time Complexity: O(N)

 ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=NULL){
            fast = fast->next;
            if(fast) fast = fast->next;
            else return NULL;
            slow = slow->next;
            if(slow == fast){
                slow = head;
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }