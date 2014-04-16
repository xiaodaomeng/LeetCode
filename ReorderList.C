/*
Reorder List
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //time O(n),space O(1)
    void reorderList(ListNode *head) {
        if(!head||!head->next) return;
        ListNode *runner=head,*slower=head;
        while(runner->next&&runner->next->next){
            runner=runner->next->next;
            slower=slower->next;
        }
        ListNode *left=head,*right=slower->next;
        slower->next=NULL;
        right=reverse(right);
        //merge
        while(right&&left){
            ListNode *tmp=right->next;
            right->next=left->next;
            left->next=right;
            left=left->next->next;
            right=tmp;
        }
    }
    ListNode* reverse(ListNode *head){
        if(!head||!head->next) return head;
        ListNode dummy(0);
        ListNode *pre=&dummy;
        pre->next=head;
        ListNode *cur=pre->next;
        while(cur->next){
            ListNode *tmp=cur->next;
            cur->next=tmp->next;
            tmp->next=pre->next;
            pre->next=tmp;
        }
        return dummy.next;
    }
};
