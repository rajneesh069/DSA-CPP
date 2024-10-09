#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


int countNodesinLoop(Node *head) {
        Node* slow = head;
        Node* fast = head;
        while(fast!=NULL){
            fast = fast->next;
            if(fast) fast = fast->next;
            else return 0;
            slow = slow->next;
            
            if(slow == fast){
                slow = head;
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                
                Node *temp = slow;
                int count = 0;
                
                do{
                    count++;
                    temp = temp->next;
                }while(temp!=slow);
                
                return count;
            }
        }
        return 0;
    }