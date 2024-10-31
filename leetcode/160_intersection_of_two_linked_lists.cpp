#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// unoptimal soln.
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode *temp = headA;
        int m = 0, n =0;
        while(temp){
            temp = temp->next;
            m++;
        }
        temp = headB;
        while(temp){
            temp = temp->next;
            n++;
        }
        if(m<n){
            ListNode *temp1 = headA;
            ListNode *temp2 = headB;
            int diff = n-m;
            while(diff--){
                temp2 = temp2->next;
            }
            while(temp1 && temp2 && temp1!=temp2){
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            return temp2;
            
        }else if(m>n){
           ListNode *temp1 = headA;
            ListNode *temp2 = headB;
            int diff = m-n;
            while(diff--){
                temp1 = temp1->next;
            }
            while(temp1 && temp2 && temp1!=temp2){
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            return temp2;
        }else{
            ListNode *temp1 = headA;
            ListNode *temp2 = headB;
            while(temp1 && temp2 && temp1!=temp2){
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            return temp2;
        }
        return nullptr;
    }

//optimal soln.
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if(!headA || !headB) return NULL;
        ListNode *tempA = headA;
        ListNode *tempB = headB;
        while(tempA!=tempB){
            if(tempA==nullptr) tempA = headB;
            else tempA = tempA->next;

            if(tempB==nullptr) tempB = headA;
            else tempB = tempB->next;
        }

        return tempA;
    }

int main(){
    
    
    return 0;
}